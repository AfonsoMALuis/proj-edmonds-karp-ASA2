i=10
for i in {10..100..5}; do
  j=1
  for j in {1..5}; do
    ./gen2procs ${i} 100 ${j}> IN/test${i}_${j}.in
    for k in {1..100}; do
      (time ./main < IN/test${i}_${j}.in >> trash.out) 2> currtime.out
      echo $(grep "user" currtime.out | cut -f2 | cut -d "m" -f2 | cut -d "s" -f1) >> results/times${i}_${j}.out
    done
  done
done

for i in {110..1000..10}; do
  for j in {1..5}; do
    ./gen2procs ${i} 100 ${j}> IN/test${i}_${j}.in
    for k in {1..100}; do
      (time ./main < IN/test${i}_${j}.in >> trash.out) 2> currtime.out
      echo $(grep "user" currtime.out | cut -f2 | cut -d "m" -f2 | cut -d "s" -f1) >> results/times${i}_${j}.out
    done
  done
done


# for i in {600..8000..100}; do
#   for j in {1..5}; do
#     ./randomDAG ${i} 1 > IN/test${i}_${j}.in
#     for k in {1..5}; do
#       (time ./main < IN/test${i}_${j}.in >> trash.out) 2> currtime.out
#       echo $(grep "user" currtime.out | cut -f2 | cut -d "m" -f2 | cut -d "s" -f1) >> results/times${i}_${j}.out
#     done
#   done
# done
