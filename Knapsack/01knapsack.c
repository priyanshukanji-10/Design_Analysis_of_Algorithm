#include <stdio.h>
#include <stdlib.h>

void print(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%.2f\t", arr[i]);
    }
    printf("\n");
}

void swap(float *a, float *b)
{
    float c = *a;
    *a = *b;
    *b = c;
}

void scan(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
}
void bubbleKnapsack(float val[], float wgh[], float ratio[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                swap(&ratio[j], &ratio[j + 1]);
                swap(&val[j], &val[j + 1]);
                swap(&wgh[j], &wgh[j + 1]);
            }
        }
    }
}

void knapSack(float val[], float wgh[], float ratio[], int n, float knapCap)

{
    int i = 0;
    int *x = (int *)calloc(n, sizeof(int));
    float maxValue = 0;
    while (knapCap > 0 && i < n)
    {
        if (wgh[i] <= knapCap)
        {
            knapCap = knapCap - wgh[i];
            x[i] = 1;
            maxValue += val[i];
        }
        else
        {
            x[i] = 0;
        }
        i++;
    }
    printf("Maxvalue : %f", maxValue);
    printf("Taken items array: \n");
    for (int j = 0; j < n; j++)
    {
        printf("%d\t", x[j]);
    }
}
int main()
{

    int n, i;
    printf("Enter no of items : ");
    scanf("%d", &n);
    float val[n], wgh[n], ratio[n];
    printf("Enter values :");
    scan(val, n);
    printf("Enter weights :");
    scan(wgh, n);
    for (i = 0; i < n; i++)
    {
        ratio[i] = val[i] / wgh[i];
    }

    printf("All datas :\n");

    printf("Values :\n");
    print(val, n);

    printf("Weights :\n");
    print(wgh, n);

    printf("Ratios :\n");
    print(ratio, n);

    bubbleKnapsack(val, wgh, ratio, n);
    printf("Sorted!! \n");

    printf("Values :\n");
    print(val, n);

    printf("Weights :\n");
    print(wgh, n);

    printf("Ratios :\n");
    print(ratio, n);

    float KnapCap;
    printf("Enter Knapsack Capacity: ");
    scanf("%f", &KnapCap);
    knapSack(val, wgh, ratio, n, KnapCap);
}