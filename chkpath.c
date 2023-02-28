#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

struct Graph
{
    int V;
    int *graph[];
};

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < graph->V; i++)
    {
        graph->graph[i] = (int *)malloc(sizeof(int) * graph->V);
        memset(graph->graph[i], -1, sizeof(int) * graph->V);
    }

    return graph;
}

void addEdge(struct Graph *graph, int u, int v)
{
    graph->graph[u][v] = v;
    graph->graph[v][u] = u;
}

bool isReachable(struct Graph *graph, int s, int d)
{
    bool visited[graph->V];
    memset(visited, false, sizeof(visited));

    int queue[graph->V];
    memset(queue, -1, sizeof(queue));

    queue[0] = s;
    visited[s] = true;

    int i = 0;
    int j = 0;
    while (queue[i] != -1)
    {
        int n = queue[i];

        if (n == d)
        {
            return true;
        }

        for (int k = 0; k < graph->V; k++)
        {
            if (graph->graph[n][k] != -1 && visited[k] == false)
            {
                queue[++j] = k;
                visited[k] = true;
            }
        }

        i++;
    }

    return false;
}

int main()
{
    int n = 3;
    int edges[][2] = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0;
    int destination = 2;

    struct Graph *graph = createGraph(n);
    for (int i = 0; i < sizeof(edges) / sizeof(edges[0]); i++)
    {
        addEdge(graph, edges[i][0], edges[i][1]);
    }

    printf("%s", isReachable(graph, source, destination) ? "true" : "false");

    return 0;
}