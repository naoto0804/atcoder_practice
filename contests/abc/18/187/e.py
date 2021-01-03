# # Make IO faster
# import sys
# input = sys.stdin.readline

# # get single (or) multiple str
# X = input()

# # get single int
# N = int(input())
# # get multiple int (e.g., 2)
# X, Y = map(int, input().split())
# # get multiple int (e.g., 2) for N lines
# XY = [list(map(int, input().split())) for _ in range(N)]

# from IPython import embed; embed(); exit();

# 全部入り
import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, fabs, gcd
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left, insort_left
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

N = int(input())
edge = []
g = [list() for i in range(N)]
for i in range(N - 1):
    A, B = map(int, input().split())
    A -= 1
    B -= 1
    edge.append((A, B))
    g[A].append(B)
    g[B].append(A)

# あるポイントを根にして，根からの深さを決定
depth = [-1] * N
depth[0] = 0
q = [0]
while q:
    at = q.pop()
    for i in g[at]:
        if depth[i] == -1:
            depth[i] = depth[at] + 1
            q.append(i)

s = [0] * N
Q = int(input())
for i in range(Q):
    T, E, X = map(int, input().split())
    A, B = edge[E - 1]
    if depth[A] > depth[B]:
        A, B = B, A
        T ^= 3
    if T == 1:
        s[0] += X
        s[B] -= X
    else:
        s[B] += X

# 累積和を取る
q = [0]
while q:
    at = q.pop()
    for i in g[at]:
        if depth[at] < depth[i]:
            s[i] += s[at]
            q.append(i)

for i in s:
    print(i)

