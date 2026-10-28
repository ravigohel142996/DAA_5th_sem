# Practical: 12 - Travelling Salesman Problem (TSP)
# Name: Ravi Gohel
# Enrollment No: 92510118030
# Objective: Implement TSP using Dynamic Programming with Bitmasking (Held-Karp Algorithm)
# Course: 01AI0304 - DAA Lab

INF = float('inf')

# Distance matrix representing cost between cities 0, 1, 2, 3
# graph[i][j] represents distance/cost to travel from city i to city j
graph = [
    [0,  10, 15, 20],
    [10, 0,  35, 25],
    [15, 35, 0,  30],
    [20, 25, 30, 0]
]

N = len(graph)
ALL_VISITED = (1 << N) - 1  # Bitmask representing all cities visited (1111 in binary = 15)

# Memoization table: stores result for (mask, current_city)
memo = {}


def solve_tsp(mask, u):
    """
    Finds minimum cost to visit all remaining cities in 'mask'
    starting from city 'u' and returning to starting city 0.
    mask: bitmask of visited cities
    u: current city
    """
    # Base Case: All cities visited, return cost from last city back to start (city 0)
    if mask == ALL_VISITED:
        return graph[u][0]

    # Return precomputed result if already calculated
    if (mask, u) in memo:
        return memo[(mask, u)]

    min_cost = INF
    # Try visiting every unvisited city v
    for v in range(N):
        if not (mask & (1 << v)):  # Check if city v is not visited
            cost = graph[u][v] + solve_tsp(mask | (1 << v), v)
            if cost < min_cost:
                min_cost = cost

    memo[(mask, u)] = min_cost
    return min_cost


def reconstruct_path():
    """Reconstructs the optimal tour path taken by the salesman."""
    mask = 1  # Start at city 0 (bitmask 0001)
    u = 0
    path = [0]

    while mask != ALL_VISITED:
        next_city = -1
        best_val = INF
        for v in range(N):
            if not (mask & (1 << v)):
                if (mask | (1 << v)) == ALL_VISITED:
                    cost = graph[u][v] + graph[v][0]
                else:
                    cost = graph[u][v] + memo[(mask | (1 << v), v)]

                if cost < best_val:
                    best_val = cost
                    next_city = v

        path.append(next_city)
        mask |= (1 << next_city)
        u = next_city

    path.append(0)  # Return to starting city 0
    return path


# Driver Code
if __name__ == "__main__":
    print("TRAVELLING SALESMAN PROBLEM (Dynamic Programming)")
    print("=" * 55)
    print("\nDistance Matrix (Cost between cities):")
    for row in graph:
        print(row)

    print(f"\nNumber of cities (N): {N}")
    print(f"All visited mask: {bin(ALL_VISITED)} ({ALL_VISITED})")

    min_cost = solve_tsp(1, 0)
    path = reconstruct_path()

    print(f"\nMinimum Tour Cost: {min_cost}")
    print("Optimal Tour Path: " + " -> ".join(map(str, path)))

    # Show all possible tours for verification (N=4, brute force)
    print("\n--- Verification: All Possible Tours from City 0 ---")
    import itertools
    cities = list(range(1, N))
    best = INF
    best_path = None
    for perm in itertools.permutations(cities):
        tour = [0] + list(perm) + [0]
        cost = sum(graph[tour[i]][tour[i+1]] for i in range(len(tour)-1))
        marker = ""
        if cost < best:
            best = cost
            best_path = tour
        # Mark optimal
        if cost == min_cost:
            marker = " <- Optimal"
        print(f"{' -> '.join(map(str, tour))} = {cost}{marker}")

    print(f"\nVerified Minimum Cost: {best} via {' -> '.join(map(str, best_path))}")
    print("\nTime Complexity: O(N^2 * 2^N)")
    print("Space Complexity: O(N * 2^N)")
