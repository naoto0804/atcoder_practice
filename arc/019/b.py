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

S = input()
N = len(S)
# なりかけ度判定
unmatch = 0
for i in range(N // 2):
    if S[i] != S[N - 1 - i]:
        unmatch += 1

if unmatch == 0:
    if N % 2 == 0: # ABBA
        ans = 25 * N
    else: # A?A
        ans = 25 * (N - 1)
elif unmatch == 1: # ABCA
    ans = 25 * N - 2
else:
    ans = 25 * N
print(ans)
