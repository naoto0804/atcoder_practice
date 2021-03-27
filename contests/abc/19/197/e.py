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

# Observation
# (1) for each color, route should be x (prev-color) -> left -> right or x -> right -> left
# (2) no need to consider O(2^{#color}), because at each color level, the best routes ending left or right (only 2) should be kept (O(#color))
N = INT()
counter = defaultdict(list)
counter[N + 1].append(0)
for i in range(N):
    x, c = list(MAP())
    counter[c].append(x)
for k, v in counter.items():
    counter[k] = sorted(v)

data = sorted(counter.items(), key=lambda x:x[0])
# array of (left_min, left_pos), (right_min, right_pos))
tmp = [[0, 0], [0, 0]]
for j, d in enumerate(data):
    (lm, lp), (rm, rp) = tmp
    new_lp, new_rp = d[1][0], d[1][-1]
    new_lm = min(lm + abs(new_rp - lp), rm + abs(new_rp - rp)) + abs(new_rp - new_lp)  # x -> l -> r, x -> r -> l
    new_rm = min(lm + abs(new_lp - lp), rm + abs(new_lp - rp)) + abs(new_rp - new_lp)  # x -> l -> r, x -> r -> l
    tmp = [[new_lm, new_lp], [new_rm, new_rp]]
print(tmp[0][0])
