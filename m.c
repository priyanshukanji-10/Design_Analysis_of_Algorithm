#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "random.h"

double getTime()
{
    LARGE_INTEGER t, freq;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&freq);
    return (double)t.QuadPart / (double)freq.QuadPart;
}

long swap(long *a, long *b)
{
    long c = *a;
    *a = *b;
    *b = c;
}

long partition(long arr[], long lb, long ub)
{
    long start = lb, end = ub;
    long pivot = arr[lb];
    while (start < end)
    {
        while (pivot >= arr[start] && start < ub)
        {
            start++;
        }
        while (pivot < arr[end] && end > lb)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}

long quickSort(long arr[], long ub, long lb)
{
    if (ub > lb)
    {
        {
            long pi = partition(arr, ub, lb);
            quickSort(arr, lb, pi - 1);
            quickSort(arr, pi + 1, ub);
        }
    }

    void main()
    {
        long n;
        printf("Enter number of elements: ");
        scanf("%ld", &n);
        long *arr = newData(n), i;

        double start = getTime();
        quickSort(arr, 0, n - 1);
        double end = getTime();

        for (i = 0; i < n; i++)
        {
            printf("%ld ", arr[i]);
        }
        double exeTime = (double)(end - start);
        printf("\nExecution time is : %lf", exeTime);
    }