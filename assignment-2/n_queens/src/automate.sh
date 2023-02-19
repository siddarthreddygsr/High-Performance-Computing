#! /bin/bash

gcc n_queens.c -fopenmp -o nqn
for thread in 1 2 4 6 8 10 12 14 16
do
	for size in 14 16
	do
		./nqn $size $thread
	done
done

