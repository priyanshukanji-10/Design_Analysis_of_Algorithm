#include <windows.h>
#include <stdio.h>
void swap(long *a, long *b)
{
    long tmp = *a;
    *a = *b;
    *b = tmp;
}
long partition(long arr[], long lb, long ub)
{
    long start = lb;
    long end = ub;
    long pivot = arr[lb];
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
    if (lb < ub)
    {
        long pi = partition(arr, lb, ub);
        quickSort(arr, lb, pi - 1);
        quickSort(arr, pi + 1, ub);
    }
}

void main()
{
    long arr[] = {78, 56, 8, 1, 32};
    long n = sizeof(arr) / sizeof(arr[0]), i;
    quickSort(arr, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%ld ", arr[i]);
    }
}