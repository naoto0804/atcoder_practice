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


def gcd(a, b):
    assert a > b
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def special_gcd(a, b):
    assert a > b
    if b == 0:
        return a, []
    else:
        val, k_list = gcd(b, a % b)
        return val, k_list + [a // b]


def solve(a, b):
    # find the solution for ax + by = 1 if x and y is coprime
    flag = a < b
    if flag:
        a, b = b, a
    val, k_list = special_gcd(a, b)
    arr = np.array([[0, 1], [1, -k_list[0]]])
    for i in range(len(k_list) - 1):
        arr = np.matmul(arr, np.array([[0, 1], [1, -k_list[i + 1]]]))
    (x0, y0), (u, v) = arr
    if flag:
        x0, y0 = y0, x0
    return x0, y0

print(solve(3, 2))

T = INT()
for t in T:
    N, S, K = list(MAP())
    # x週目にy回目の移動で座れる (x >= 1, y >= 1)
    # S + Ky = Nx

    # https://mathtrain.jp/axbyc
    # ax + by = cが整数解を持つ→cはgcd(a, b)の倍数
    if c % gcd(K, N) != 0:
        print(-1)
    else:
        x0, y0 = solve(a, b)
