import numpy as np

N = int(input())
# O(N ^ {2})
# w_list, h_list = [], []
# hw_set = set()
# for i in range(N):
#     w, h = list(map(int, input().split()))
#     hw_set.add((h, w))
#     w_list.append(w)
#     h_list.append(h)
# H, W = max(h_list), max(w_list)
# dp = np.zeros((H + 1, W + 1, 2))  # last ind is for (cnt, is_box_exist)

# for i in range(1, H + 1):
#     for j in range(1, W + 1):
#         is_box_exist = 0
#         cnt = max([dp[i - 1, j, 0], dp[i, j - 1, 0]])
#         if dp[i - 1, j, 1] + dp[i, j - 1, 1] == 0:
#             if (i, j) in hw_set:
#                 cnt += 1
#                 is_box_exist = 1

#         dp[i][j] = (cnt, is_box_exist)
# print(int(dp.max()))

# http://abc038.contest.atcoder.jp/data/abc/038/editorial.pdf
# O(NlogN)

import bisect
wh = [[0, 0]for _ in range(N)]
for i in range(N):
    wh[i][0], wh[i][1] = list(map(int, input().split()))
wh.sort(key=lambda x:(x[0], -x[1]))  # wは昇順，hは降順
inf = 10 ** 6
# dp[i]は，長さiの増加部分列を作るときの，最後の番号の最小値
dp = [inf] * N
ans = 0

# (w, h) = (2, 2), (3, 3), (4, 1) と来ると，，
for i in range(N):
    h = wh[i][1]
    a = bisect.bisect_left(dp, h)
    print(dp)
    dp[a] = h
    ans = max(ans, a)

print(ans + 1)
