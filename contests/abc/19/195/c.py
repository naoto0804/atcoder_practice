import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
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
if N < 1000:
    print(0)
    exit()

n = N
n_comma = 0
ans = 0
while n >=1000:
    n_comma += 1
    n = n // 1000

ans += n_comma * (N + 1 - (1000 ** n_comma))
for i in range(1, n_comma):
    ans += i * (1000 ** (i + 1) - 1000 ** i)
print(ans)
