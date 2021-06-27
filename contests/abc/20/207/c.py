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
# import numpy as np
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

EPS = 0.01
N = INT()
data = []
for i in range(N):
    t, l, r = MAP()
    if t == 2:
        r = r - EPS
    elif t == 3:
        l = l + EPS
    elif t == 4:
        r = r - EPS
        l = l + EPS
    data.append((l, r, t))

data = sorted(data, key=lambda x: x[0])
cnt = 0
for i in range(N):
    for j in range(N):
        if i >= j: continue
        if data[j][0] <= data[i][1]:
            cnt = cnt + 1
print(cnt)
