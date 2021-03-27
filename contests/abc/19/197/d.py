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

N = INT()
x_0, y_0 = list(MAP())
x_1, y_1 = list(MAP())

x_c = (x_0 + x_1) / 2.0
y_c = (y_0 + y_1) / 2.0
x_0, x_1 = x_0 - x_c, x_1 - x_c
y_0, y_1 = y_0 - y_c, y_1 - y_c

theta = radians(360 / N)
cost = cos(theta)
sint = sin(theta)
x = cost * x_0 - sint * y_0 + x_c
y = sint * x_0 + cost * y_0 + y_c
print(x, y)
