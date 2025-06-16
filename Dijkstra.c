#include <stdio.h>
#include <limits.h>
#define V 5

int minDis(int dist[], int visited[])
{
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < V; i++)
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }

    return min_index;
}

void dijkstra(int graph[V][V], int start)
{
    int dist[V];
    int visited[V];
    int i, j;

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        int u = minDis(dist, visited);
        visited[u] = 1;

        for (int j = 0; j < V; j++)
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
    }

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V], i, j, start;

    printf("Enter the cost matrix:");
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("\nEnter the source node:");
    scanf("%d", &start);
    dijkstra(graph, start);

    return 0;
}
