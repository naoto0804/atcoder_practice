# modified BFS
# first search all the aisles, and then search n_berak = 1, then 2, ...

import numpy as np
from collections import deque

H, W = list(map(int, input().split()))

visited = np.full((H, W), False)
board = np.zeros((H, W))
for i in range(H):
    row = input()
    for j, r in enumerate(row):
        if r == '#':
            board[i][j] = 1
        elif r == 's':
            s_y, s_x = i, j
        elif r == 'g':
            g_y, g_x = i, j

direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
queue = deque()
queue.append(((s_y, s_x), 0))  # (pos, n_break)


while len(queue) > 0:
    (y, x), n_break = queue.popleft()
    if x == g_x and y == g_y:
        break

    for dx, dy in direction:
        new_y, new_x = y + dy, x + dx
        if new_y < 0 or new_y >= H or new_x < 0 or new_x >= W:
            continue
        if visited[new_y][new_x]:
            continue
        if board[new_y][new_x] == 0:
            queue.appendleft(((new_y, new_x), n_break))
        else:  # will search later because there might be better option
            queue.append(((new_y, new_x), n_break + 1))
        visited[new_y][new_x] = True

if n_break <= 2:
    print("YES")
else:
    print("NO")
