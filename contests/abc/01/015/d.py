# TLE..
import numpy as np
W = int(input())
N, K = list(map(int, input().split()))
A, B = [], []
for _ in range(N):
    a, b = list(map(int, input().split()))
    A.append(a)  # width
    B.append(b)  # importance

# M = int(input())
# B = list(map(int, input().split()))

# dp[i][j][k]: 幅合計i,枚数合計j,k枚目までのときの最大値
dp = np.zeros((W + 1, K + 1, N + 1)).astype(np.uint32)
for i in range(1, W + 1):
    for j in range(1, K + 1):
        for k in range(1, N + 1):
            if i - A[k - 1] >= 0:
                dp[i, j, k] = max([dp[i, j, k - 1], dp[i - A[k - 1], j - 1, k - 1] + B[k - 1]])
            else:
                dp[i, j, k] = dp[i, j, k - 1]

print(dp.max())
