#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<sys/time.h>
#include<math.h>

// Function to perform block matrix multiplication
void block_matrix_mult(int size, int nt, int power, int block_size) {
    int i, j, k, ii, jj, kk;
    struct timeval tv1, tv2;
    struct timezone tz;
    int pow;
    // int size_arr[3] = {512, 1024 ,2048};

    // for(int s=0; s<3; s++){
        // for(int power =2; power<=16; power++){
            // for(int nt = 1; nt<=16; nt = nt*2){
                // for(int block_size = 4; block_size<=64; block_size = block_size*2){
                
                    // int N = size_arr[s];
                    int N = size;
                    double (*A)[N] = malloc(N * N * sizeof(double));
                    double (*result)[N] = malloc(N * N * sizeof(double));
                    double elapsed; 

                    //Generating a matrix which has values b/w 0 and 1

                    for(i = 0; i<N; i++){
                        for(j=0; j<N; j++){
                            A[i][j] = ((float)rand()/ (float)(RAND_MAX));
                            printf("%f ",A[i][j]);
                        }
                        printf("\n");
                    }

                    omp_set_num_threads(nt);
                    gettimeofday(&tv1,&tz);


                    #pragma omp parallel for private(i,j,k,power, ii, jj, kk) shared(A,result)
                    // Multiply blocks of size 'block_size'
                    
                    for(pow = 0; pow<power; pow++){
                        for (ii = 0; ii < N; ii += block_size) {
                            for (jj = 0; jj < N; jj += block_size) {
                                for (kk = 0; kk < N; kk += block_size) {
                                    // Multiply block matrices
                                    for (i = ii; i < ii + block_size && i < N; i++) {
                                        for (j = jj; j < jj + block_size && j < N; j++) {
                                            for (k = kk; k < kk + block_size && k < N; k++) {
                                                result[i][j] += A[i][k] * A[k][j];
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    gettimeofday(&tv2, &tz);

                    printf("\n");
                    for(i = 0; i<N; i++){
                        for(j=0; j<N; j++){
                            printf("%f ",result[i][j]);
                        }
                        printf("\n");
                    }
                    elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;

                    printf("%4.2lf %d %d %d %d\n", elapsed, size, power, nt, block_size);

                    

                    
                // }
            // }
        // }
    // }
}

int main(int argc, char*argv[]) {
   

    int size=atoi(argv[1]);
	int numTh=atoi(argv[2]);
	int pow=atoi(argv[3]);
    int block=atoi(argv[4]);
    if(block > size){
        printf("Block Size cannot be greater than matrix size\n");
        return 0;
    }
    // Call block matrix multiplication function
    block_matrix_mult(size,numTh,pow,block);

    // Print the result matrix
    

    return 0;
}