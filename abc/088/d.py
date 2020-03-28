import numpy as np
from collections import deque

H, W = list(map(int, input().split()))
s_y, s_x = 0, 0
g_y, g_x = H - 1, W - 1

visited = np.full((H, W), False)
board = np.zeros((H, W))
for i in range(H):
    row = input()
    for j, r in enumerate(row):
        if r == '.':
            board[i][j] = 1

direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
queue = deque()
queue.append(((s_y, s_x), 0))  # (pos, dist)

found = False
while len(queue) > 0:
    (y, x), dist = queue.popleft()
    if x == g_x and y == g_y:
        found = True
        break

    for dx, dy in direction:
        new_y, new_x = y + dy, x + dx
        if new_y < 0 or new_y >= H or new_x < 0 or new_x >= W:
            continue
        if board[new_y][new_x] == 0:
            continue
        if visited[new_y][new_x]:
            continue
        queue.append(((new_y, new_x), dist + 1))
        visited[new_y][new_x] = True
if found:
    print(int(np.sum(board)) - (dist + 1))
else:
    print(-1)
