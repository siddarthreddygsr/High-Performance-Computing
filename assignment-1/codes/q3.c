#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>


int main(int argc, char*argv[]) 
{


    struct timeval tv1, tv2;
    struct timezone tz;
    double elapsed;
    
    int i,j,p;

    int mat_size_arr[5] = {2, 3, 512,1024, 2048};

    for (int mat_ind  = 0; mat_ind < 2; mat_ind++)
    {
        int size = mat_size_arr[mat_ind];

        for(int power =2; power<=16; power++)
        {
            for(int nt = 1; nt<=16; nt = nt*2)
            {
                // long double  **A = get_rand_array(size);

                long double (*A)[size] = malloc(size * size * sizeof(long double));

                long double (*C)[size] = malloc(size * size * sizeof(long double));
                
                for(int m = 0; m < size; m++)
                {
                    for(int n = 0; n < size; n++)
                    {
                        A[m][n] = (long double)rand()/RAND_MAX;
                    }
                }

                for (int i = 0; j < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        printf("%lf ", A[i][j]);
                    }
                    printf("\n");
                }

                printf("\n\n");

                for(int m = 0; m < size; m++)
                {
                    for(int n = 0; n < size; n++)
                    {
                        C[m][n] = 0;
                    }
                }


                long double (*A1)[size] = malloc(size * size * sizeof(long double));

                for (int m = 0; m < size; m++)
                {
                    for (int n = 0; n < size; n++)
                    {
                        A1[m][n] = A[m][n];
                    }
                }


                for(int m = 0; m < size; m++)
                {
                    for(int n = 0; n < m; n++)
                    {
                        long double temp = A1[m][n];
                        A1[m][n] = A1[n][m];
                        A1[n][m] = temp;
                    }
                }

                omp_set_num_threads(nt);
                
                gettimeofday(&tv1, &tz);

                #pragma omp parallel for private(i,j,p) shared(A,A1,C)
                for(p = 0; p < power; ++p){

                    for (i = 0; i < size; ++i) 
                    {
                        for (j = 0; j < size; ++j)
                        {
                            C[i][j] += A[i][j]*A1[i][j];
                        }
                    }
                }
                

                gettimeofday(&tv2, &tz);

                elapsed = (double) ( tv2.tv_sec - tv1.tv_sec) + (double) (tv2.tv_usec - tv1.tv_usec) * 1.e-6;

                printf("%4.2lf size =  %d pow = %d nt = %d\n", elapsed, mat_size_arr[mat_ind], power, nt);

            }
        }
    }

    return 0;
}

