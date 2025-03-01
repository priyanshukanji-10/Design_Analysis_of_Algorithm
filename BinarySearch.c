#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
#include <windows.h>

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
double getTime()
{
    LARGE_INTEGER t, freq;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&freq);
    return (double)t.QuadPart / (double)freq.QuadPart;
}
long BinarySearch(long a[], long l, long r, long sElem)
{
    if (r >= l)
    {
        long mid = (r + l) / 2;
        if (a[mid] == sElem)
            return mid;
        else if (a[mid] < sElem)
            return BinarySearch(a, mid + 1, r, sElem);
        else
            return BinarySearch(a, l, mid - 1, sElem);
    }
    return -1;
}

int main()
{
    long n;
    printf("Enter number of elements: ");
    scanf("%ld", &n);
    long *a = newData(n);

    long i;

    quickSort(a, 0, n);

    printf("\nSorted\n");

    printf("%ld \t", a[50000]);

    printf("\nEnter element to search: ");
    long sElem;
    scanf("%ld", &sElem);
    long index;

    double start = getTime();

    index = BinarySearch(a, 0, n - 1, sElem);

    double end = getTime();

    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", index);

    double exTime = (double)(end - start);

    printf("Execution time is: %lf seconds\n", exTime);

    free(a);
    return 0;
}