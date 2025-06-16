#include <stdio.h>

void merge(int arr[], int lb, int ub, int m)
{
    int n1 = m - lb + 1;
    int n2 = ub - m;
    int l[n1], r[n2];
    int i, j;
    for (i = 0; i < n1; i++)
    {
        l[i] = arr[lb + i];
    }
    for (j = 0; j < n2; j++)
    {
        r[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    int k = lb;
    while (i < n1 && j < n2)
    {
        if (r[j] < l[i])
        {
            arr[k] = r[j];
            j++;
        }
        else
        {
            arr[k] = l[i];
            i++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = l[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int m = lb + (ub - lb) / 2;
        mergeSort(arr, lb, m);
        mergeSort(arr, m + 1, ub);
        merge(arr, lb, ub, m);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
