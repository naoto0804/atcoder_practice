import numpy as np
N, K = map(int, input().split())
A = np.array([input() for _ in range(N)], dtype=np.int64)
Acum = np.zeros(N+1, dtype=np.int64)
Acum[1:] = A.cumsum()

# dp[n][k] = n日目時点でk回機嫌がよくなる場合の最小勝利回数
INF = 2**31-1
dp = np.full((N+1, N+1), INF, dtype=np.int64)
dp[1, 0] = 0
dp[1, 1] = 1

for n in range(2, N+1):
    # n日目に機嫌がよくならない
    dp[n] = dp[n-1]
    # n日目に機嫌がよくなる
    x = Acum[n-1]
    y = Acum[n]
    # n-1目でk/x として、k/x < K/y iff (yk/x) < K iff [yk/x] < K
    # numpyだと一気に行演算で誤魔化せる
    dp[n, 1:] = np.minimum(dp[n, 1:], 1 + y * dp[n-1, :-1] // x)

answer = np.searchsorted(dp[N], K, side='right') - 1
# 例外処理：全勝になってしまう場合
if K == Acum[-1]:
    answer = 1
print(answer)
