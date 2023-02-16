#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

double **A;
double **B;
double **C;

int main(int argc, char*argv[]) 
{
	// matrix size, num Threads, power
	int i,j,k,p;
	struct timeval tv1, tv2;
	struct timezone tz;
	double elapsed; 
	int size=atoi(argv[1]);
	int numTh=atoi(argv[2]);
	int pow=atoi(argv[3]);
	int N=size;
	double sum=0.0;
	//printf("Size is %d",N);
	A=(double **)calloc(sizeof(double *), size);
	B=(double **)calloc(sizeof(double *), size);
	C=(double **)calloc(sizeof(double *), size);
	for(i=0;i<size;i++)
	{
		A[i]=(double *)calloc(sizeof(double), size);
		B[i]=(double *)calloc(sizeof(double), size);
		C[i]=(double *)calloc(sizeof(double), size);
	}
	omp_set_num_threads(numTh);
	for (i= 0; i< N; i++)
	for (j= 0; j< N; j++)
	{
		A[i][j] = 2;
		B[i][j] = 2;
	}
	//printf("NumbeLEVEL3_CACHE_LINESIZE         r of Threads: %d",omp_get_num_procs());
	gettimeofday(&tv1, &tz);

	#pragma omp parallel for private(i,j,k,p) shared(A,B,C)

    for(p = 0; p < pow; ++p){
    	for (i = 0; i < N; ++i) {
    		for (j = 0; j < N; ++j) {
    			for (k = 0; k < N; ++k) { C[i][j]+=A[i][k] * B[k][j];  }
    		}
    	}
    }
	gettimeofday(&tv2, &tz);

	elapsed = (double) (tv2.tv_sec-tv1.tv_sec) + (double) (tv2.tv_usec-tv1.tv_usec) * 1.e-6;
	printf("elapsed time = %4.2lf seconds.\n", elapsed);
	
	/*for (i= 0; i< N; i++)  { 
		for (j= 0; j< N; j++) {  
			printf("%lf\t",C[i][j]); 
		} 
	printf("\n"); LEVEL3_CACHE_LINESIZE              64

	}*/
}
