#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int prims(int v, int graph[v][v])
{
    int ne = 0;
    int u, ve, i, j, min;
    int minCost = 0;
    int *visited = (int *)calloc(v, sizeof(int));
    visited[0] = 1;
    while (ne < v - 1)
    {
        min = INT_MAX;
        for (i = 0; i < v; i++)
        {
            if (visited[i] != 0)
            {
                for (j = 0; j < v; j++)
                {
                    if (visited[j] == 0 && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        ve = j;
                    }
                }
            }
        }
        if (visited[u] != 0 && visited[ve] == 0)
        {
            graph[u][ve] = graph[ve][u] = INT_MAX;
            visited[ve] = 1;
            minCost += min;
            printf("Edge %d. (%d--%d) : %d \n", ne + 1, u + 1, v + 1, min);
            ne++;
        }
    }
    printf("Minimum cost - %d", minCost);
}

int main()
{
    int v;
    printf("Enter no of Vertices : ");
    scanf("%d", &v);
    int graph[v][v];
    printf("Enter Graph :");
    int i, j;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }
    prims(v, graph);
}