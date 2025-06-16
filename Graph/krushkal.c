#include <stdio.h>
#include <limits.h>

int parent[10] = {0};

int find(int i)
{
    while (parent[i] != 0)
    {
        i = parent[i];
    }
    return i;
}
void krushkal(int n, int graph[n][n])
{
    int ne = 0, i, j, a, b, u, v, min;
    int minCost = 0;
    printf("All edges in minimum spanning tree: \n");
    while (ne < n - 1)
    {
        min = INT_MAX;
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < n; j++)
            {
                if (graph[i][j] < min)
                {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        v = find(v);
        u = find(u);
        if (u != v)
        {
            parent[v] = u;
            printf("Edge %d : (%d--%d) : %d\n", ne + 1, a + 1, b + 1, min);
            minCost += min;
            ne++;
            graph[a][b] = graph[b][a] = INT_MAX;
        }
    }
    printf("Min cost : %d", minCost);
}
int main()
{
    int n;
    printf("Enter no of Vertices : ");
    scanf("%d", &n);
    int graph[n][n];
    printf("Enter Graph :");
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    krushkal(n, graph);
    return 0;
}