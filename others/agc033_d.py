import numpy as np
H, W = list(map(int, input().split()))
A = np.zeros((H, W))
for i in range(H):
    string = input()
    for j, s in enumerate(string):
        if s == '#':
            A[i][j] = 1  # black
        else:
            A[i][j] = 0  # white

