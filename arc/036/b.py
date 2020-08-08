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

N = INT()
h = []
for i in range(N):
    h.append(INT())

# L, R は自分の場所より手前の単調増加列の長さ
inv_h = list(reversed(h))
L = [INF for _ in range(N)]
L[0] = 0

inv_R = [INF for _ in range(N)]
inv_R[0] = 0

l_cnt = 0
for i in range(N - 1):
    if h[i] < h[i + 1]:
        l_cnt += 1
    else:
        l_cnt = 0
    L[i + 1] = l_cnt

r_cnt = 0
for i in range(N - 1):
    if inv_h[i] < inv_h[i + 1]:
        r_cnt += 1
    else:
        r_cnt = 0
    inv_R[i + 1] = r_cnt

R = list(reversed(inv_R))

ans_max = -INF
for i in range(N):
    tmp = L[i] + R[i] + 1
    if tmp > ans_max:
        ans_max = tmp
print(ans_max)
