# 個数制限なしナップサック
# 1次元DPに落とせる
h, n = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(n)]
dp =[0]*(h+max(a for a,b in ab))
for i in range(1, h+1):
    dp[i] = min(dp[i-a]+b for a,b in ab)
print(dp[h])
