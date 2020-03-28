# clique and tree detection by DFS

from collections import defaultdict
from collections import deque

N, M = list(map(int, input().split()))
edges = defaultdict(set)
for i in range(M):
    n1, n2 = input().split()
    edges[n1].add(n2)
    edges[n2].add(n1)

tree_cnt = 0
not_used_nodes = [True] * N

while any(not_used_nodes):
    start_node = str(not_used_nodes.index(True) + 1)

    queue = deque()
    visited = set()
    visited.add(start_node)
    queue.append((None, start_node))
    loop_flag = False

    while len(queue) > 0:
        prev_node, node = queue.pop()
        visited.add(node)
        not_used_nodes[int(node) - 1] = False
        for next_node in edges[node]:
            if next_node == prev_node:
                continue  # we store bidirectional flow in dict, so just ignore
            if next_node in visited:
                loop_flag = True
                continue
            queue.append((node, next_node))
    if not loop_flag:
        tree_cnt += 1

print(tree_cnt)
