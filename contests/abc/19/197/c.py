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
A = list(MAP())


def f_or(start, end):
    if start == end:
        return A[start]
    else:
        tmp = A[start]
        for i in range(start + 1, end):
            tmp = tmp | A[i]
        return tmp


def f_xor(nums):
    if len(nums) == 1:
        return nums[0]
    else:
        tmp = nums[0]
        for i in range(len(nums) - 1):
            tmp = tmp ^ nums[1 + i]
        return tmp

# 2^20 ~= 10^6, make sure to use pypy3
# bit全探索
ans = INF
for i in range(2 ** (N - 1)):
    bag = set()
    tmp = 0
    # add leftmost and rightmost indices to make slices
    inds = [0]
    for j in range(N - 1):
        if ((i >> j) & 1):
            inds.append(j + 1)
    inds.append(N)

    arr = []  # elements in arr will be XOR'ed
    for j in range(len(inds) - 1):
        arr.append(f_or(inds[j], inds[j+1]))
    tmp = f_xor(arr)
    if tmp < ans:
        ans = tmp
print(ans)
