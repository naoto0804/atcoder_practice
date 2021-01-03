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

N = INT()
ab_list = [list(MAP()) for _ in range(N)]
sum_a = sum(ab_list[i][0] for i in range(N))
sum_b = 0

# (効果量, Aの減少量, Bの増加量)
x = [(2 * a + b, -a, a + b) for (a, b) in ab_list]
x = sorted(x, key=lambda x: x[0], reverse=True)

# 効果量が多い方から演説していって，投票数が超えたら終了
ind = 0
while sum_a >= sum_b:
    sum_a += x[ind][1]
    sum_b += x[ind][2]
    ind += 1

print(ind)
