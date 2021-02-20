import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
# from fractions import gcd
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

# 概ね典型的なダイクストラ，待ち時間の処理だけ注意

N, M, X, Y = list(MAP())
connections = [[] for _ in range(N)]
data = dict()
for i in range(M):
    a, b, t, k = list(MAP())
    a -= 1
    b -= 1
    connections[a].append(b)
    connections[b].append(a)
    data[(a,b)] = (t, k)
    data[(b,a)] = (t, k)

# print(connections)
# print(data)

q = []
heappush(q, (0, X - 1))  # time 0 at node 0

times = [-1 for _ in range(N)]

while len(q) > 0:
    now_t, ind = heappop(q)
    if times[ind] >= 0:  # visited
        if now_t < times[ind]:
            times[ind] = now_t
    else:
        times[ind] = now_t
    for next_ind in connections[ind]:
        t, k = data[(ind, next_ind)]

        if now_t % k == 0:
            next_t = now_t + t
        else:
            next_t = now_t + (k - now_t % k) + t
        if times[next_ind] < 0 or next_t < times[next_ind]:
            heappush(q, (next_t, next_ind))
print(times[Y - 1])
