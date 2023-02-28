# Helper function to find the set that an element i belongs to
def find(parent, i):
    if parent[i] == i:
        return i
    return find(parent, parent[i])

# Function to perform union of two sets of x and y


def union(parent, rank, x, y):
    xroot = find(parent, x)
    yroot = find(parent, y)
    if rank[xroot] < rank[yroot]:
        parent[xroot] = yroot
    elif rank[xroot] > rank[yroot]:
        parent[yroot] = xroot
    else:
        parent[yroot] = xroot
        rank[xroot] += 1

# Function to find the missing edge value in the graph


def findMissingEdge(total_mst_cost, mst_cost_without_edge, graph):
    num_vertices = len(graph)

    # Initialize result
    result = []

    # Initialize each vertex as a parent
    parent = []
    rank = []

    for node in range(num_vertices):
        parent.append(node)
        rank.append(0)

    # Initialize edges as a list of tuples (src, dest, weight)
    edges = []
    for i in range(num_vertices):
        for j in range(num_vertices):
            if graph[i][j] != 0:
                edges.append((i, j, graph[i][j]))

    # Sort edges in ascending order by weight
    edges = sorted(edges, key=lambda x: x[2])

    # Initialize MST cost
    mst_cost = 0

    # Iterate through all sorted edges
    for edge in edges:
        src, dest, weight = edge
        x = find(parent, src)
        y = find(parent, dest)

        # If including this edge does not cause a cycle,
        # include it in result and update MST cost
        if x != y:
            result.append(edge)
            mst_cost += weight
            union(parent, rank, x, y)

    # Find the missing edge by subtracting the MST cost without the edge
    # from the total MST cost
    missing_edge_cost = total_mst_cost - (mst_cost - mst_cost_without_edge)

    return missing_edge_cost


# Test with given input
total_mst_cost = 17
mst_cost_without_edge = 15
graph = [[0, 7, 8, 0, 0, 0],
         [7, 0, 3, 6, 0, 5],
         [8, 3, 0, 4, 0, 3],
         [0, 6, 4, 0, 5, 2],
         [0, 0, 0, 5, 0, 2],
         [0, 5, 3, 2, 2, 0]]

missing_edge_cost = findMissingEdge(
    total_mst_cost, mst_cost_without_edge, graph)
print("The missing edge value is", missing_edge_cost)
