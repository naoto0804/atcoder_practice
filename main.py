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

N, M = list(MAP())
cond = defaultdict(int)
for i in range(M):
    a, b = list(MAP())
    cond[(a, b)] += 1

K = INT()
CD = []
for i in range(K):
    CD.append(list(MAP()))

ans = 0
#bit全探索
for i in range(2 ** K):
    bag = set()
    tmp = 0
    for j in range(K):
        if ((i >> j) & 1):
            bag.add(CD[j][1])
        else:
            bag.add(CD[j][0])

    for (a, b), cnt in cond.items():
        if a in bag and b in bag:
            tmp += cnt

    if tmp > ans:
        ans = tmp
print(ans)
