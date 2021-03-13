import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
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

N, M, Q = list(MAP())
WV = [list(MAP()) for _ in range(N)]
WV = sorted(WV, key=lambda x:-x[1])
X = list(MAP())
LR = [list(MAP()) for _ in range(Q)]

for i in range(Q):
    l, r = LR[i]
    X_now = X[:l-1] + X[r:]
    X_now = sorted(X_now)

    ans = 0
    for (w, v) in WV:
        if len(X_now) == 0:
            break
        index = bisect_left(X_now, w)
        if index < len(X_now):
            ans += v
            X_now.pop(index)
    print(ans)
