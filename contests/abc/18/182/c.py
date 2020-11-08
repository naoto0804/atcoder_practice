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

# A, B = list(MAP())
# print(2 * A + 100 - B)

N = INT()
cnt = [0, 0, 0]
while N > 0:
    cnt[N % 10 % 3] += 1
    N = N // 10
N_digits = sum(cnt)

tmp = (1 * cnt[1] + 2 * cnt[2]) % 3
if tmp == 0:
    print(0)
elif tmp == 1:
    if cnt[1] >= 1 and cnt[1] < N_digits:
        print(1)
    elif cnt[2] >= 2 and cnt[2] < N_digits:
        print(2)
    else:
        print(-1)
else:
    if cnt[2] >= 1 and cnt[2] < N_digits:
        print(1)
    elif cnt[1] >= 2 and cnt[1] < N_digits:
        print(2)
    else:
        print(-1)
