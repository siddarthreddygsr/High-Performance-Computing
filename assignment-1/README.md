# Lab 4

## Folder Structure
```
├── README.md
├── REPORT_LAB.pdf
├── codes
│   ├── q1.c
│   ├── q2.c
│   ├── q3.c
│   └── q4.c
├── graph_notebooks
│   ├── q1_graph.ipynb
│   ├── q2_graphs.ipynb
│   ├── q3_graph.ipynb
│   └── q4_graphs.ipynb
├── graphs
│   ├── q1_op.dat
│   ├── q2_op.dat
│   ├── q3_op.dat
│   └── q4_op.dat
└── outputs
    ├── q1.txt
    ├── q2.txt
    ├── q2_2048-mec.txt
    ├── q3.txt
    ├── q31_2048.txt
    ├── q3_res.txt
    └── q4.txt
```
codes: This directory contains source code files for each question which are named q1.c, q2.c, q3.c, and q4.c.

graph_notebooks: This directory contains Jupyter notebooks named q1_graph.ipynb, q2_graphs.ipynb, q3_graph.ipynb, and q4_graphs.ipynb. These notebooks are used for generating graphs to visualize the results obtained from the C code.

graphs: This directory is used to store the graphs or plots generated using the notebooks in the graph_notebooks directory.

## CODES OVERVIEW

1. `q1.c` : Ordinary matrix multiplication parallelized with openMP for different Matrix sizes and powers
2. `q2.c` : Block matrix multiplication parallelized with openMP for different Matrix sizes, Block sizes and powers
3. `q3.c` : Ordinary matrix multiplication using Transpose matrix parallelized with openMP for different Matrix sizes and powers
4. `q4.c` : Block matrix multiplication using Transpose matrix parallelized with openMP for different Matrix sizes, Block sizes and powers

## Functions OVERVIEW

1. `block_matrix_mult()` : C code to perform block matrix multiplication with different block sizes parallalized with openMP

## COMPILATION

1. `gcc q1.c -fopenmp q1`
2. `gcc q2.c -fopenmp q2`
3. `gcc q3.c -fopenmp q3`
4. `gcc q4.c -fopenmp q4`

## EXECUTION

1. `./q1 <matrix_size> <num_threads> <power>`
2. `./q2` [ Q2 has no command-line arguments]
3. `./q3` [ Q3 has no command-line arguments]
4. `./q4` [ Q4 has no command-line arguments]

## AUTHORS

1. Siddarth Reddy Gurram [SE20UARI144]
2. Sreevaatsav [SE20UARI147]
3. Lohit Garje [SE20UARI089]
4. Chaitanya Srikanth [SE20UARI038]
5. Sravanthi [SE20UCSE076]


