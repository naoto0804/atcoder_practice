import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
import numpy as np
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N, W = MAP()
v, w = ZIP(N)

if N <= 30:  # 半分全列挙
	left = [(0, 0)]  # 前半
	right = [(0, 0)]  # 後半
	for i in range(N//2):
		left += [(x+w[i], y+v[i]) for x, y in left]
	for i in range(N//2, N):
		right += [(x+w[i], y+v[i]) for x, y in right]
	left.sort(key=lambda x:(x[0], -x[1]))
	right.sort(key=lambda x:(x[0], -x[1]))
	# 無駄なものを取り除く
	tmp = []
	tmp_v = -1
	for w, v in left:
		if w > W:
			break
		if v > tmp_v:
			tmp_v = v
			tmp.append((w, v))
	left = tmp[:]

	tmp = []
	tmp_v = -1
	for w, v in right:
		if w > W:
			break
		if v > tmp_v:
			tmp_v = v
			tmp.append((w, v))
	right = tmp[:]

	w_2, v_2 = zip(*right)
	ans = 0
	for w, v in left:
		idx = bisect(w_2, W-w)
		ans = max(ans, v+v_2[idx-1])
	print(ans)

elif max(w) <= 1000:  # 普通のナップサック
	L = N*1000+1  # 多めに確保する
	dp = np.zeros(L, dtype=np.int64)
	n = 1
	for w, v in zip(w, v):
		dp[w:w+n] = np.maximum(dp[w:w+n], dp[:n] + v)
		n += w
	print(dp[:W+1].max())

else:  # 重み最小化ナップサック
	L = N*1000+1  # 多めに確保する
	dp = np.zeros(L, dtype=np.int64)
	dp[1:] = 10**18
	n = 1
	for w, v in zip(w, v):
		dp[v:v+n] = np.minimum(dp[v:v+n], dp[:n]+w)
		n += v
	v_lis = np.where((dp<=W)!=0)[0]  # タプルが返ってくる
	print(v_lis.max())
