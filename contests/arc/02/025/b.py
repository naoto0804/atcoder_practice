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


# 二次元いもす法
# np.cumsumでミスを防ぐ

h, w = MAP()
B = np.zeros((h, w)).astype(np.int32)
W = np.zeros((h, w)).astype(np.int32)
for i in range(h):
    row = list(MAP())
    for j, r in enumerate(row):
        if (i + j) % 2 == 0:
            B[i][j] = r
        else:
            W[i][j] = r

acc_B = np.zeros((h + 1, w + 1)).astype(np.int32)
acc_W = np.zeros((h + 1, w + 1)).astype(np.int32)
acc_B[1:, 1:] = np.cumsum(np.cumsum(B, axis=0), axis=1)
acc_W[1:, 1:] = np.cumsum(np.cumsum(W, axis=0), axis=1)

area_max = 0
for y1 in range(h + 1):
    for y2 in range(h + 1):
        if y1 >= y2: continue
        for x1 in range(w + 1):
            for x2 in range(w + 1):
                if x1 >= x2: continue
                sum_W = acc_W[y2][x2] - acc_W[y2][x1] - acc_W[y1][x2] + acc_W[y1][x1]
                sum_B = acc_B[y2][x2] - acc_B[y2][x1] - acc_B[y1][x2] + acc_B[y1][x1]
                if sum_W == sum_B:
                    area = (y2 - y1) * (x2 - x1)
                    if area_max < area:
                        area_max = area
print(area_max)
