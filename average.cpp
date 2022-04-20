#include <iostream>
#include <string>

using namespace std;

string replaceChar(string str) {
  for (unsigned long i = 0; i < str.length(); ++i) {
    if (str[i] == ',')
      str[i] = '.';
  }
  return str;
}

int main(){
  double v, total=0;
  string input;
  for (int i = 0; i<100; i++){
    cin >> input;
    input = replaceChar(input);
    v = stod(input);
    total+=v;
  }
  cout << total/100 << endl;
  return 1;
}
