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

X = input()
M = INT()
d = int(max(X, key = lambda x: int(x)))

def proc(x, n):
	s = 0
	for i in X:
		s *= n
		s += int(i)
	return s

l = d
r = 10 ** 19 + 100

while l < r:
    m = (r - l) // 2 + l
    print(l, r, m)
    if proc(X, m) <= M:
        l = m
    else:
        r = m

if l > 10 ** 19:
	print(1)
else:
	print(l - d)

    # if key == arr[m]:
    #     return m
    # elif key < arr[m]:
    #     r = m
    # else:
    #     l = m + 1
# return -1

# cnt = 0
# for i in range(d + 1, 60):
#     tmp = 0
#     for x in X:
#         tmp = tmp * i + int(x)
#     if tmp <= M:
#         cnt += 1
#     else:
#         break
#     # print(i, tmp)
# print(cnt)
