# Practical : 09 - Implementation of Prim's algorithm using greedy method
# Name : Ravi Gohel | Enrolment No: 92510118030
# Objective : To implement Prim's algorithm to find the Minimum Spanning Tree (MST)
#             of a connected, weighted, undirected graph.

# Prim's Minimum Spanning Tree (adjacency matrix)
INF = float('inf')

graph = [
    [0, 4, 3, 0, 0, 0],
    [4, 0, 1, 2, 0, 0],
    [3, 1, 0, 4, 0, 0],
    [0, 2, 4, 0, 2, 7],
    [0, 0, 0, 2, 0, 6],
    [0, 0, 0, 7, 6, 0]
]

n = len(graph)
key = [INF] * n        # cheapest edge weight connecting each vertex to the tree
parent = [-1] * n      # tree vertex that the cheapest edge comes from
in_mst = [False] * n
key[0] = 0  # start from vertex 0
total = 0

print("PRIM'S ALGORITHM")
for step in range(n):
    # pick the vertex outside the tree with the smallest key
    u = -1
    for v in range(n):
        if not in_mst[v] and (u == -1 or key[v] < key[u]):
            u = v
    if key[u] == INF:
        raise ValueError("Graph is disconnected")
    in_mst[u] = True
    total += key[u]
    if parent[u] == -1:
        print(f"Step {step}: start at vertex {u}")
    else:
        print(f"Step {step}: add vertex {u} using edge {parent[u]}-{u} (weight {key[u]})")
    # update keys of the neighbours of u
    for v in range(n):
        if graph[u][v] > 0 and not in_mst[v] and graph[u][v] < key[v]:
            key[v] = graph[u][v]
            parent[v] = u

print("Edges in the MST:")
for v in range(1, n):
    print(f" {parent[v]} - {v} : {graph[parent[v]][v]}")
print("Total cost of MST =", total)
