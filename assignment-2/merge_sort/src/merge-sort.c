#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <sys/time.h>

#define ARRAY_SIZE 40000000

void merge_sort(int *array, int *tmp, int size);
void merge_r(int *src, int *tmp, int start, int mid, int end);
void ins_sort(int *src, int start, int end);

int main(int argc, char *argv[])
{
    struct timeval tv1, tv2;
    struct timezone tz;
    double elapsed;
    int numTh = atoi(argv[1]);
    omp_set_num_threads(numTh);
    int i;
    int *src, *tmp;
    src = (int *)malloc(ARRAY_SIZE * sizeof(int));
    tmp = (int *)malloc(ARRAY_SIZE * sizeof(int));

    srand(time(NULL));

    // generate random numbers for int type array
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        src[i] = rand();
    }
    /*
    printf("before sorting\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d \t",src[i]);
      }
    printf("\n");*/

    // sort int type array
    gettimeofday(&tv1, &tz);

    merge_sort(src, tmp, ARRAY_SIZE);
    gettimeofday(&tv2, &tz);

    elapsed = (double)(tv2.tv_sec - tv1.tv_sec) + (double)(tv2.tv_usec - tv1.tv_usec) * 1.e-6;
    printf("%lf %d %d\n", elapsed, numTh, ARRAY_SIZE);
    /*printf("after sorting\n");
    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("%d \t",src[i]);

      }
    printf("\n");*/
    for (i = 1; i < ARRAY_SIZE && (src[i - 1] <= src[i]); i++)
        ;
    if (i == ARRAY_SIZE)
    {
        printf("Test passed");
    }
    else
    {
        printf("Test Failed");
    }
    free(src);
    free(tmp);

    return 0;
}

void merge_sort(int *src, int *tmp, int size)
{
    int i, stride = 100;
    int mxlimit = size - stride;
    #pragma omp parallel for
    for (i = 0; i < mxlimit; i = i + stride)
    {
        ins_sort(src, i, i + stride - 1);
        // printf("Thread %d is running number %d to %d\n", omp_get_thread_num(), i, i+stride-1);
    }
    // i = size-size%stride;
    for (i = 0; i < mxlimit; i = i + stride)
        ;
    if (i < size)
    {
        ins_sort(src, i, size - 1);
    }

    mxlimit = size - (2 * stride);
    while (stride < size)
    {
#pragma omp parallel for
        for (i = 0; i < mxlimit; i = i + 2 * stride)
        {
            merge_r(src, tmp, i, i + stride, i + 2 * stride - 1);
            // printf("Thread %d is running number %d to %d\n", omp_get_thread_num(), i, i+(2*stride)-1);
        }
        for (i = 0; i < mxlimit; i = i + 2 * stride)
            ;
        // i = size-size%stride;
        // printf("\ni = %d\n\n\n",i);
        if (i + stride < size)
        {
            merge_r(src, tmp, i, i + stride, size - 1);
        }
        stride = 2 * stride;
        mxlimit = size - (2 * stride);
        // printf("\nstride = %d\n\n\n",stride);
    }
}
void ins_sort(int *src, int start, int end)
{
    for (int pos = start + 1; pos <= end; pos++)
    {
        int temp = src[pos];
        while (pos > start && src[pos - 1] > temp)
        {
            src[pos] = src[pos - 1];
            pos = pos - 1;
        }
        if (pos >= start)
        {
            src[pos] = temp;
        }
    }
}

void merge_r(int *src, int *tmp, int start, int mid, int end)
{
    int i = start, j = mid, k = start;
    while (i <= mid - 1 && j <= end)
    {
        if (src[i] <= src[j])
        {
            tmp[k++] = src[i++];
        }
        else
        {
            tmp[k++] = src[j++];
        }
    }
    while (i <= mid - 1)
    {
        tmp[k++] = src[i++];
    }
    while (j <= end)
    {
        tmp[k++] = src[j++];
    }
    i = start;
    j = end;
    while (i <= j)
    {
        src[i] = tmp[i];
        i++;
    }
}
