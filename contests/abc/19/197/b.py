import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
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

H, W, X, Y = list(MAP())
S = []
for i in range(H):
    S.append(input())
X -= 1
Y -= 1

cnt = 1
for (d_x, d_y) in [[-1, 0], [0, -1], [1, 0], [0, 1]]:
    x, y = X, Y
    while True:
        x, y = x + d_x, y + d_y
        if x < 0 or x >= H or y < 0 or y >= W or S[x][y] == '#':
            break
        else:
            cnt += 1
print(cnt)
