#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

class Graph{

public:
    int nNodes;
    int **adjMatrix;
    explicit Graph(int V);
    void addEdge(int u, int v, int w) const;
};

Graph::Graph(int V) {
    this->nNodes = V;
    this->adjMatrix = new int *[V];
    for (int i = 0; i < V; ++i) {
        adjMatrix[i] = new int [V];
        for (int j = 0; j < V; j++)
            adjMatrix[i][j] = 0;
    }
}

void Graph::addEdge(int u, int v, int w) const {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
}



bool BFS(const Graph& graph, int s, int path[]) {
    bool visited[graph.nNodes];
    for (int i = 1; i < graph.nNodes; i++)
        visited[i] = false; //same as setting to white
    visited[s] = true;
    path[s] = -1;

    queue<int> q;
    q.push(s);
    bool thereIsPath = false;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int w = 0; w < graph.nNodes; w++) {
            if (!visited[w] && graph.adjMatrix[v][w] > 0) { //checks if it's white and if it still has room for more flow
                if (w == graph.nNodes-1) { //if we reach t, then there is a path
                    path[w] = v;
                    thereIsPath = true;
                    break;
                }
                q.push(w);
                path[w] = v;
                visited[w] = true;
            }
        }
        if (thereIsPath) break;
    }
    return thereIsPath;
}

int edmondsKarp(const Graph& graph, int s, int t) {
    int u, v;

    int path[graph.nNodes];

    int max_flow = 0;

    while (true) {

        bool existsPath = BFS(graph, s, path);
        if (!existsPath) return max_flow;

        int path_flow = INT_MAX;

        for (v = t; v != s; v = path[v]) {
            u = path[v];
            path_flow = min(path_flow, graph.adjMatrix[u][v]); //sets path flow to the min existent in the path
        }

        for (v = t; v != s; v = path[v]) {
            u = path[v];
            graph.adjMatrix[u][v] -= path_flow; //sets the existing flow to the correspondent edge
            graph.adjMatrix[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
}


Graph parseInputs() {
    int nProcesses, nEdges;
    cin >> nProcesses >> nEdges;
    Graph processes = Graph(nProcesses+2);
    if (nProcesses < 2 || nEdges < 0){
        cerr << "The number of nodes must be >= 2 and the number of edges must be >= 0" << endl;
        exit(0);
    }
    for (int i = 0; i<nProcesses; i++){
        int n1, n2;
        cin >> n1 >> n2;
        processes.addEdge(0, i+1, n1);
        processes.addEdge(nProcesses+1, i+1, n2);
    }

    for (int i = 0; i<nEdges; i++){
        int src, dest, weight;
        cin >> src >> dest >> weight;
        if ( src > nProcesses || dest > nProcesses || src < 1 || dest < 1){
            cerr << "The Node Number is invalid, please provide a number between 1 and " << nProcesses << endl;
            exit(0);
        }
        processes.addEdge(src, dest, weight);
    }
    return processes;
}

void printGraph (const Graph& processes) { //used to check if the graph is built correctly
    cout << "i ||";
    for (int i = 1; i <= processes.nNodes - 2; i++)
        cout << " " << i << " |";
    cout << endl;

    cout << "Xi ||";
    for (int i = 0; i < processes.nNodes; i++) {
        if (processes.adjMatrix[0][i] != 0)
            cout << " " << processes.adjMatrix[0][i] << " |";
    }
    cout << endl;

    cout << "Yi ||";
    for (int i = 0; i < processes.nNodes; i++) {
        if (processes.adjMatrix[processes.nNodes-1][i] != 0)
            cout << " " << processes.adjMatrix[processes.nNodes-1][i] << " |";
    }
    cout << endl;

    cout << endl;
    cout << "Cij ||";
    for (int i = 1; i < processes.nNodes-1; ++i) {
        cout << " " << i << " |";
    }
    cout << endl;

    for (int i = 1; i < processes.nNodes-1; i++) {
        cout << i << " ||";
        for (int j = 1; j < processes.nNodes-1; ++j)
            cout << " " << processes.adjMatrix[i][j] << " |";
        cout << endl;
    }
}

int main() {
    Graph processes = parseInputs();

//    cout << "=============================================" << endl;
//    printGraph(processes);
//    cout << "=============================================" << endl;

    cout << edmondsKarp(processes, 0, processes.nNodes-1) << endl;

    return 0;
}
