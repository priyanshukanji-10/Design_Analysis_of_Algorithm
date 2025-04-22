#include <stdio.h>
#include <stdlib.h>

void print(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%.2f \t", arr[i]);
    }
    printf("\n");
}
void scan(float arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
}
void swap(float *a, float *b)
{
    float c = *a;
    *a = *b;
    *b = c;
}
void bubbleKnapsack(float r[], float p[], float w[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r[j] < r[j + 1])
            {
                swap(&r[j], &r[j + 1]);
                swap(&w[j], &w[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }
}
void fractionalknapsack(float p[], float w[], float r[], int cap, int n)
{
    int capC = cap;
    float maxProf = 0;
    float *frac = (float *)calloc(n, sizeof(float));
    int i = 0;
    while (capC > 0 && i < n)
    {
        if (w[i] <= capC)
        {
            maxProf += p[i];
            frac[i] = 1.0;
        }
        else
        {
            maxProf += r[i] * capC;
            frac[i] = capC / w[i];
        }

        capC = capC - w[i];
        i++;
    }
    printf("Max Profit is : %.2f", maxProf);
    printf("\nFractions taken : \n");
    print(frac, n);
}

int main()
{
    printf("Fractional Knapsack\n");
    printf("Enter no of items :");
    int n;
    scanf("%d", &n);
    float p[n], w[n], r[n];
    printf("Enter values of profit: ");
    scan(p, n);
    printf("Enter values of weights: ");
    scan(w, n);
    int i;
    for (i = 0; i < n; i++)
    {
        r[i] = p[i] / w[i];
    }
    printf("Enter capacity of the Knapsack :");
    int cap;
    scanf("%d", &cap);

    printf("All values :\n");

    printf("Count :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t", i + 1);
    }
    printf("\n");

    printf("Profit :\n");
    print(p, n);

    printf("Weight :\n");
    print(w, n);

    printf("Ratiio :\n");
    print(r, n);

    printf("Sorting data with respect to ratio...\n");

    bubbleKnapsack(r, p, w, n);

    printf("Sorted\n");

    printf("Count :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \t", i + 1);
    }
    printf("\n");

    printf("Profit :\n");
    print(p, n);

    printf("Weight :\n");
    print(w, n);

    printf("Ratiio :\n");
    print(r, n);

    fractionalknapsack(p, w, r, cap, n);
}