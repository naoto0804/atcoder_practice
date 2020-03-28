from collections import defaultdict
N, M = list(map(int, input().split()))

edge_dict = defaultdict(set)
for i in range(M):
    a, b = list(map(int, input().split()))
    edge_dict[a].add(b)
    edge_dict[b].add(a)

def search(node: int, visited: set):
    visited.add(node)
    if len(visited) == N:
        return 1

    ans = 0
    for next_node in edge_dict[node]:
        if not next_node in visited:
            ans += search(next_node, visited.copy())
    return ans

visited = set()
node = 1
print(search(node, visited))
