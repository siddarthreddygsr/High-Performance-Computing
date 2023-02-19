#! /bin/bash
gcc merge-sort.c -fopenmp -o merge-parallel
for thread in 1 2 4 6 8 10 12 14 16
do
	./merge-parallel $thread
done

