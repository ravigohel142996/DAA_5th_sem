# Practical: 11 - Floyd-Warshall Algorithm
# Name: Ravi Gohel
# Enrollment No: 92510118030
# Objective: Implement Floyd-Warshall algorithm to find All-Pairs Shortest Paths
# Course: 01AI0304 - DAA Lab

INF = float('inf')

def floyd_warshall(graph):
    """
    Implements Floyd-Warshall Algorithm for All-Pairs Shortest Path.
    graph: adjacency matrix where graph[i][j] is weight of edge i->j, INF if no edge.
    Returns shortest distance matrix.
    """
    V = len(graph)
    # Initialize distance matrix with graph values
    dist = [row[:] for row in graph]

    # Dynamic Programming: k is the intermediate vertex
    for k in range(V):
        for i in range(V):
            for j in range(V):
                # If vertex k is on the shortest path from i to j, update dist[i][j]
                if dist[i][k] != INF and dist[k][j] != INF:
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]

    # Check for negative weight cycles
    for i in range(V):
        if dist[i][i] < 0:
            raise ValueError("Graph contains a negative weight cycle!")

    return dist


def print_matrix(matrix, title="Matrix"):
    print(f"\n{title}:")
    for row in matrix:
        print([r if r != INF else "INF" for r in row])


# Driver Code
if __name__ == "__main__":
    # Graph represented as an adjacency matrix (V = 4)
    # INF represents no direct edge between vertices
    graph = [
        [0,   3,   INF, 7],
        [8,   0,   2,   INF],
        [5,   INF, 0,   1],
        [2,   INF, INF, 0]
    ]

    print("FLOYD-WARSHALL ALGORITHM (All-Pairs Shortest Path)")
    print("=" * 55)

    print("\nInitial Distance Matrix (Direct Edges):")
    for row in graph:
        print([r if r != INF else "INF" for r in row])

    # Compute shortest distance matrix
    shortest_dist = floyd_warshall(graph)

    print("\nFinal Shortest Distance Matrix:")
    for row in shortest_dist:
        print([r if r != INF else "INF" for r in row])

    # Additional detailed trace (k iterations)
    print("\n--- Step-wise Trace ---")
    V = len(graph)
    dist = [row[:] for row in graph]
    print("\nD(-1) Initial Matrix:")
    for row in dist:
        print([r if r != INF else "INF" for r in row])

    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] != INF and dist[k][j] != INF:
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        print(f"\nD({k}) After considering vertex {k} as intermediate:")
        for row in dist:
            print([r if r != INF else "INF" for r in row])

    print("\nTime Complexity: O(V^3)")
    print("Space Complexity: O(V^2)")
