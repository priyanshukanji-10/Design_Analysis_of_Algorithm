#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long *newData(long n)
{
    long *a = (long *)malloc(n * sizeof(long));
    long lim = n * 2;
    srand(time(NULL));
    long i;
    for (i = 0; i < n; i++)
    {
        a[i] = (rand() * rand()) % lim;
    }
    return a;
}