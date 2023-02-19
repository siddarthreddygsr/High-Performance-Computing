#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>
#include <sys/time.h>

int isSafe(int** arr, int x, int y, int N){

    //Check the row

    for(int i=0; i<N; i++){
        if(arr[x][i] == 1){
            return 0;
        }
    }

    //Check the column

    for(int i=0; i<N; i++){
        if(arr[i][y] == 1){
            return 0;
        }
    }

    //Checking the 4 diagonals of the (x,y)

    int row = x;
    int col = y;

    while (row<N && col<N){
        if(arr[row][col] == 1){
            return 0;
        }
        row++;
        col++;
    }

    row = x;
    col = y;

    while (row<N && col>=0){
        if(arr[row][col] == 1){
            return 0;
        }
        row++;
        col--;
    }

    row = x;
    col = y;

    while (row>=0 && col<N){
        if(arr[row][col] == 1){
            return 0;
        }
        row--;
        col++;
    }

    row = x;
    col = y;

    while (row>=0 && col>=0){
        if(arr[row][col] == 1){
            return 0;
        }
        row--;
        col--;
    }

    return 1;  //Return 1 if all the above conditions are satisfied
}

void print_board(int **arr, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int n_queens(int** arr, int col, int N){


    if(col==N){
        // print_board(arr,N);
        // printf("\n\n");
        return 1;
    }
    
    int count = 0;
    #pragma omp parallel for reduction(+:count)
    for(int i=0; i<N; i++){
        if(isSafe(arr, i, col, N) == 1){
            arr[i][col] = 1;
        #pragma omp atomic
        count += n_queens(arr, col+1, N);
        arr[i][col] = 0;
        }

       
    }   
}



int main(int argc, char*argv[]){

    //Creating a chess board in 2D
    //1 represents a queen, 0 represents empty slot.

    int N = atoi(argv[1]);
	int num_th = atoi(argv[2]);

    // src = (int *)malloc(ARRAY_SIZE * sizeof(int));

    // int** arr = (int*)malloc(sizeof(int), N);
    // for (int i = 0; i < N; i++){
    //     arr[i] = (int*)malloc(sizeof(int), N);
    // }

    int rows = N;
    int columns = N;
    int **arr;

    arr = (int **)malloc(rows * sizeof(int *));
    for (int i=0; i<N; i++)
        arr[i] = (int *)malloc(columns * sizeof(int));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            arr[i][j] =0;
            // printf("%d ",arr[i][j]);
        }
        // printf("\n");
    }

    struct timeval tv1, tv2;
	struct timezone tz;
	double elapsed; 

    omp_set_dynamic(0);     // Explicitly disable dynamic teams
    omp_set_num_threads(num_th);

    gettimeofday(&tv1, &tz);
    n_queens(arr, 0, N);
    gettimeofday(&tv2, &tz);
    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;

    printf("%4.2lf %d %d\n", elapsed, N, num_th);

}