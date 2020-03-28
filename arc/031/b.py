import numpy as np
from collections import deque

H, W = 10, 10
board = np.zeros((H, W))
for i in range(H):
    strings = input()
    for j, s in enumerate(strings):
        if s == 'o':
            board[i][j] = 1
# H, W = 3, 3
# board = np.array([[1, 0, 0], [0, 0, 1], [0, 0, 0]])

sum_land = np.sum(board)
direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]

flag = False
for i in range(H):
    for j in range(W):
        if board[i][j] == 1:
            continue
        queue = deque()
        queue.append((i, j))
        visited = np.full((H, W), False)

        cnt = 0
        # start search
        while len(queue) > 0:
            y, x = queue.pop()
            if not (y == i and x == j):
                cnt += 1
            # from IPython import embed; embed(); exit();
            for dy, dx in direction:
                new_y, new_x = y + dy, x + dx
                if new_y < 0 or new_y >= H or new_x < 0 or new_x >= W:
                    continue
                if board[new_y][new_x] == 0:
                    continue
                if visited[new_y][new_x]:
                    continue
                queue.append((new_y, new_x))
                visited[new_y][new_x] = True
        if cnt == sum_land:
            flag = True
            break

if flag:
    print("YES")
else:
    print("NO")
