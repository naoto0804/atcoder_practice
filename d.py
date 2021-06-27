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


def proc(pos1, pos2, pos3):
    x1, y1 = pos1
    x2, y2 = pos2
    x3, y3 = pos3

    # move (x1, y1) to (0, 0)
    x2 = x2 - x1
    x3 = x3 - x1
    y2 = y2 - y1
    y3 = y3 - y1

    # normalize
    s2 = sqrt(x2 ** 2 + y2 ** 2)
    x2 = x2 / s2
    y2 = y2 / s2
    s3 = sqrt(x3 ** 2 + y3 ** 2)
    x3 = x3 / s3
    y3 = y3 / s3

    inner = x2 * x3 + y2 * y3
    outer = x2 * y3 - x3 * y2
    return inner, outer


N = INT()
pos_S = []
for i in range(N):
    a, b = MAP()
    pos_S.append((a, b))

pos_T = []
for i in range(N):
    c, d = MAP()
    pos_T.append((c, d))

for i in range(N):
    for j in range(N):
        for k in range(N):
            s1, o1 = proc(pos_S[i], pos_S[j], pos_S[k])
            s2, o2 = proc(pos_T[i], pos_T[j], pos_T[k])
            # permutation分の不定性が残っちゃうのどうしよう..
