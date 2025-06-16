#include <stdio.h>
#include <limits.h>

int matrixChainMultiplication(int p[], int n)
{
    int m[n][n];
    int i, j, k, l, q = 0;
    for (i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l < n; l++)
    {
        for (i = 1; i < n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[j] * p[k];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main()
{
    int p[] = {10, 20, 30};
    int n = sizeof(p) / sizeof(p[0]);
    int x = matrixChainMultiplication(p, n);
    printf("No of multiplication is: %d", x);
}