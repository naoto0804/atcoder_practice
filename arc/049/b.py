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


# コストに関する二分探索に持ち込む
# あるコストのときに到達可能な領域の最大と最小を保持し，それが全部の点を見たときに最大>最小であるようにする

def binary_search(X, l, r):
    for i in range(64):
        mid = l + (r - l) / 2.0
        xlow, xhigh, ylow, yhigh = -INF, INF, -INF, INF

        for j in range(len(X)):
            x, y, c = X[j]
            tmp_xlow = x - mid / c
            tmp_ylow = y - mid / c
            tmp_xhigh = x + mid / c
            tmp_yhigh = y + mid / c

            if xlow < tmp_xlow: xlow = tmp_xlow
            if ylow < tmp_ylow: ylow = tmp_ylow
            if xhigh > tmp_xhigh: xhigh = tmp_xhigh
            if yhigh > tmp_yhigh: yhigh = tmp_yhigh

        if xlow < xhigh and ylow < yhigh:
            r = mid
        else:
            l = mid
    return mid

N = INT()
X = []
for i in range(N):
    X.append(list(MAP()))
print(binary_search(X, 0, 1000000000))
