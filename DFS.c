#include <stdio.h>
#include <stdlib.h>

// adjacency list node
typedef struct node
{
    int dest;
    struct node *next;
} node_t;

// adjacency list
typedef struct adj_list
{
    node_t *head;
} adj_list_t;

// graph
typedef struct graph
{
    int num_vertices;
    adj_list_t *adj_lists;
} graph_t;

// create a new node
node_t *create_node(int dest)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// create a graph with num_vertices
graph_t *create_graph(int num_vertices)
{
    graph_t *new_graph = (graph_t *)malloc(sizeof(graph_t));
    new_graph->num_vertices = num_vertices;

    new_graph->adj_lists = (adj_list_t *)malloc(num_vertices * sizeof(adj_list_t));
    for (int i = 0; i < num_vertices; i++)
    {
        new_graph->adj_lists[i].head = NULL;
    }

    return new_graph;
}

// add an edge from src to dest
void add_edge(graph_t *graph, int src, int dest)
{
    node_t *new_node = create_node(dest);
    new_node->next = graph->adj_lists[src].head;
    graph->adj_lists[src].head = new_node;

    // for an undirected graph, you should also add an edge from dest to src
    // new_node = create_node(src);
    // new_node->next = graph->adj_lists[dest].head;
    // graph->adj_lists[dest].head = new_node;
}

// recursive helper function for DFS
void DFSUtil(graph_t *graph, int vertex, int *visited)
{
    visited[vertex] = 1;
    printf("visited %d\n", vertex);

    node_t *current = graph->adj_lists[vertex].head;
    while (current != NULL)
    {
        int neighbor = current->dest;
        if (!visited[neighbor])
        {
            DFSUtil(graph, neighbor, visited);
        }
        current = current->next;
    }
}

// DFS traversal of the graph
void DFS(graph_t *graph, int start_vertex)
{
    int num_vertices = graph->num_vertices;
    int visited[num_vertices];
    for (int i = 0; i < num_vertices; i++)
    {
        visited[i] = 0;
    }

    DFSUtil(graph, start_vertex, visited);
}

int main()
{
    int num_vertices, num_edges;
    printf("Enter the number of vertices and edges in the graph: ");
    scanf("%d%d", &num_vertices, &num_edges);

    graph_t *graph = create_graph(num_vertices);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < num_edges; i++)
    {
        int src, dest;
        scanf("%d%d", &src, &dest);
        add_edge(graph, src, dest);
    }

    int start_vertex;
    printf("Enter the start vertex for DFS: ");
    scanf("%d", &start_vertex);

    printf("DFS starting from vertex %d:\n", start_vertex);
    DFS(graph, start_vertex);

    return 0;
}