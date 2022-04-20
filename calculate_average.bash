i=10
for i in {10..100..5}; do
  for j in {1..5}; do
    ./getV+E < IN/test${i}_${j}.in >> nodes_edges.txt
    ./average < results/times${i}_${j}.out >> averages.txt
  done
done

for i in {110..950..10}; do
  for j in {1..5}; do
    ./getV+E < IN/test${i}_${j}.in >> nodes_edges.txt
    ./average < results/times${i}_${j}.out >> averages.txt
  done
done

# for i in {600..8000..100}; do
#   for j in {1..5}; do
#     ./average < results/times${i}_${j}.out >> averages.txt
#   done
# done
