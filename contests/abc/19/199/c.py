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
# import numpy as np
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = INT()
S = input()
Q = INT()

I = list(range(2 * N))
F = I[:N]
B = I[N:]
for i in range(Q):
    t, a, b = list(MAP())
    if t == 1:
        if a - 1 < N and b - 1 < N:
            F[a-1], F[b-1] = F[b-1], F[a-1]
        elif a - 1 >= N and b - 1 < N:
            B[a-1-N], F[b-1] = F[b-1], B[a-1-N]
        elif a - 1 < N and b - 1 >= N:
            F[a-1], B[b-1-N] = B[b-1-N], F[a-1]
        else:
            B[a-1-N], B[b-1-N] = B[b-1-N], B[a-1-N]
    else:
        F, B = B, F

# print(I)
ans = ''
for i in F:
    ans = ans + S[i]
for i in B:
    ans = ans + S[i]
print(ans)
