import numpy as np
from collections import deque

R, C = list(map(int, input().split()))
s_y, s_x = list(map(int, input().split()))
g_y, g_x = list(map(int, input().split()))

visited = np.full((R, C), False)
board = np.zeros((R, C))
for i in range(R):
    row = input()
    for j, r in enumerate(row):
        if r == '.':
            board[i][j] = 1

direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
queue = deque()
queue.append(((s_y - 1, s_x - 1), 0))  # (pos, dist)

while len(queue) > 0:
    (y, x), dist = queue.popleft()
    if x == g_x - 1 and y == g_y - 1:
        break

    for dx, dy in direction:
        new_y, new_x = y + dy, x + dx
        if new_y < 0 or new_y >= R or new_x < 0 or new_x >= C:
            continue
        if board[new_y][new_x] == 0:
            continue
        if visited[new_y][new_x]:
            continue
        queue.append(((new_y, new_x), dist + 1))
        visited[new_y][new_x] = True
print(dist)
