#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long *newData(long n)
{
    long lim = n * 2;
    long *arr = (long *)malloc(n * sizeof(long));
    long i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        arr[i] = (rand() * rand()) % lim;
    }
    return arr;
}