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

H, W = MAP()
S = []
for i in range(H):
    S.append(input())
memo = np.zeros((H, W))  # 0: 未定, 1: win, -1: lose

def is_valid(i, j):
    if (i < 0 or H <= i) or (j < 0 or W <= j) or S[i][j] == '#':
        return False
    else:
        return True

def judge(i, j):
    if not is_valid(i, j): return 1
    if memo[i][j] != 0: return memo[i][j]
    result = -1
    if judge(i+1, j) == -1: result = 1
    if judge(i, j+1) == -1: result = 1
    if judge(i+1, j+1) == -1: result = 1
    memo[i][j] = result
    return result

ans = judge(0, 0)
if ans == 1:
    print("First")
else:
    print("Second")
