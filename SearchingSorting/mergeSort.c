#include <stdio.h>
#include "random.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>

double getTime()
{
    LARGE_INTEGER t, freq;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&freq);
    return (double)t.QuadPart / (double)freq.QuadPart;
}

void merge(long arr[], long m, long l, long r)
{
    long n1 = m - l + 1, n2 = r - m;
    long left[n1], right[n2];
    long i;
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }
    for (i = 0; i < n2; i++)
    {
        right[i] = arr[m + 1 + i];
    }
    long j = 0, k = l;
    i = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(long arr[], long l, long r)
{
    if (l < r)
    {
        long m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, m, l, r);
    }
}

int main()
{
    long n;
    printf("Enter number of elements: ");
    scanf("%ld", &n);
    long *arr = newData(n), i;

    double start = getTime();
    mergeSort(arr, 0, n - 1);
    double end = getTime();

    for (i = 0; i < n; i++)
    {
        printf("%ld ", arr[i]);
    }
    double exeTime = (double)(end - start);
    printf("\nExecution time is : %lf", exeTime);
}