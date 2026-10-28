# Practical : 10 - Implementation of Kruskal's algorithm using greedy method
# Name : Ravi Gohel | Enrolment No: 92510118030
# Objective : To implement Kruskal's algorithm to find the Minimum Spanning Tree (MST)
#             using Disjoint Set Union (DSU).

# Kruskal's Minimum Spanning Tree using Disjoint Set Union (DSU)
n = 6
edges = [(0, 1, 4), (0, 2, 3), (1, 2, 1), (1, 3, 2),
         (2, 3, 4), (3, 4, 2), (3, 5, 7), (4, 5, 6)]  # (u, v, weight)

parent = list(range(n))
size = [1] * n

def find(x):
    # follow parents to the root, shortening the path on the way
    while parent[x] != x:
        parent[x] = parent[parent[x]]
        x = parent[x]
    return x

def union(a, b):
    ra, rb = find(a), find(b)
    if ra == rb:
        return False  # already in the same set -> cycle
    if size[ra] < size[rb]:
        ra, rb = rb, ra
    parent[rb] = ra  # attach smaller set under bigger set
    size[ra] += size[rb]
    return True

edges.sort(key=lambda e: e[2])  # sort edges by weight

print("KRUSKAL'S ALGORITHM")
print("Sorted edges (u, v, weight):")
for e in edges:
    print(" ", e)

mst = []
total = 0

for step, (u, v, w) in enumerate(edges, 1):
    if union(u, v):
        mst.append((u, v, w))
        total += w
        print(f"Step {step}: edge {u}-{v} (weight {w}) -> ACCEPT")
    else:
        print(f"Step {step}: edge {u}-{v} (weight {w}) -> REJECT (cycle)")
    if len(mst) == n - 1:
        print("MST has n-1 edges, stop.")
        break

if len(mst) != n - 1:
    raise ValueError("Graph is disconnected")

print("Edges in the MST:")
for u, v, w in mst:
    print(f" {u} - {v} : {w}")
print("Total cost of MST =", total)
