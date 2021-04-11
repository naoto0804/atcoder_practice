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
A = list(MAP())
inds = list(range(len(A)))
pairs = list(zip(A, inds))

for i in range(N - 1):
    new_pairs = []
    for j in range(2 ** (N - 1 - i)):
        if pairs[2 * j][0] < pairs[2 * j + 1][0]:
            new_pairs.append(pairs[2 * j + 1])
        else:
            new_pairs.append(pairs[2 * j])
    pairs = new_pairs

if pairs[0][0] < pairs[1][0]:
    print(pairs[0][1] + 1)
else:
    print(pairs[1][1] + 1)