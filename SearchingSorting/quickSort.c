#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#include <windows.h>

double getTime()
{
    LARGE_INTEGER t, freq;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&freq);
    return (double)t.QuadPart / (double)freq.QuadPart;
}

void swap(long *a, long *b)
{
    long c = *a;
    *a = *b;
    *b = c;
}
long partition(long arr[], long lb, long ub)
{
    long start = lb;
    long pivot = arr[lb];
    long end = ub;
    while (start < end)
    {
        while (arr[start] <= pivot && start <= ub)
        {
            start++;
        }
        while (arr[end] > pivot && end >= lb)
        {
            end--;
        }
        if (end > start)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[lb], &arr[end]);
    return end;
}
void quickSort(long arr[], long lb, long ub)
{
    if (ub > lb)
    {

        long pi = partition(arr, lb, ub);
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