
# Lab 2

## Folder Structure

```
.
├── README.md
├── merge_sort
│   ├── graphs
│   │   ├── merge.dat
│   │   ├── merge.pdf
│   │   ├── ms_graphs.sh
│   │   ├── output_ms_d.dat
│   │   └── output_ms_f.dat
│   └── src
│       ├── automate.sh
│       └── merge-sort.c
└── n_queens
    ├── graphs
    │   ├── 10.dat
    │   ├── 12.dat
    │   ├── 14_op.dat
    │   ├── 16_op.dat
    │   ├── n_queens.pdf
    │   └── n_queens.sh
    ├── outputs
    │   ├── 10.txt
    │   ├── 12.txt
    │   ├── 14.txt
    │   └── 16.txt
    └── src
        ├── automate.sh
        └── n_queens.c
```

## Overview

1. Merge Sort: Merge sort is a way of sorting things, like a list of numbers or words, so they end up in the right order. It splits things into smaller groups, sorts them, and then puts them back together in the right order.

2. N Queens: The n queens problem is a puzzle that involves placing n chess queens on an n x n chessboard in such a way that no two queens attack each other. The n queens algorithm is a way to solve this puzzle by systematically trying different placements for the queens until all valid solutions is found.

## Functions Overview

1. N Queens:
    - isSafe - This function checks whether it is safe to place a queen at a particular position on the chessboard. It checks the row, column, and diagonal lines of the position to ensure that no other queen is present on those lines.

    - print_board - This function prints the chessboard with the queens in their positions.

    - n_queens - This function uses backtracking to find all possible solutions to the n-queens problem. It takes three arguments - the current column, the chessboard array, and the size of the chessboard. It places a queen in the current column and then calls the n_queens function recursively for the next column until all the columns have been processed.

2. Merge Sort
    - merge_sort(int *src, int *tmp, int size): This function implements the merge sort algorithm. It takes three parameters: a pointer to the array to be sorted (src), a temporary array (tmp) used for merging, and the size of the array (size). It first sorts the array in blocks of 100 elements using the ins_sort function. Then, it repeatedly merges adjacent blocks until the entire array is sorted. The function uses OpenMP to parallelize the sorting process.

    - ins_sort(int *src, int start, int end): This function implements insertion sort, which is used to sort the small blocks of 100 elements in merge_sort. It takes three parameters: a pointer to the array to be sorted (src), the starting index of the block (start), and the ending index of the block (end). It iterates over the block and for each element, it swaps it with the previous element until the entire block is sorted in ascending order.

    - merge_r(int *src, int *tmp, int start, int mid, int end): This function merges two sorted subarrays of src into a temporary array tmp. It takes five parameters: a pointer to the array to be sorted (src), a pointer to the temporary array used for merging (tmp), the starting index of the first subarray (start), the ending index of the first subarray and the starting index of the second subarray (mid), and the ending index of the second subarray (end). The function merges the two subarrays into tmp, and then copies the merged array back to src.

## COMPILATION

1. `gcc merge-parallel.c -fopenmp merge-parallel`
2. `gcc n_queen.c -fopenmp nqueen`

## EXECUTION

1. `./marge-parallel <num_threads>`
2. `./nqueen <mat_size> <num_threads>`

## AUTHORS

1. Siddarth Reddy Gurram [SE20UARI144]
2. Sreevaatsav [SE20UARI147]
3. Lohit Garje [SE20UARI089]
4. Chaitanya Srikanth [SE20UARI038]
5. Sravanthi [SE20UCSE076]
