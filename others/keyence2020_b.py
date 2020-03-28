import numpy as np
N = int(input())
X, L = np.zeros(N), np.zeros(N)

for i in range(N):
    x, l = list(map(int, input().split()))
    X[i] = x
    L[i] = l
right_end = X + L
left_end = X - L
sorted_ind = np.argsort(right_end)

cur = int(-1e10)
cnt = 0
for i in range(N):
    if left_end[sorted_ind][i] >= cur:
        cur = right_end[sorted_ind][i]
        cnt += 1
print(cnt)
