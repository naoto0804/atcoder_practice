# 最長部分増加列問題
# dpは常にソート済みなので，ひたすら二分探索で次の要素がどこに入るか考える
# 一番右端に入ってくれると最大部分列が1伸びたことになる
# bisect_leftなので右端の値より小さいけど右端-1より大きいものは右端に入ってくれる
import bisect
N = int(input())
C = []
for i in range(N):
    C.append(int(input()))

INF = 10 ** 9
dp = [INF] * N

for i in range(N):
    num = C[i]
    idx = bisect.bisect_left(dp,num)
    dp[idx] = num
    print(num, idx, dp)
print(dp.count(INF))
