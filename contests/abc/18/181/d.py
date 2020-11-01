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
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, fabs
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left, insort_left
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

S = input()
if len(S) <= 3:
    for str_nums in permutations(S, len(S)):
        tmp = 0
        for i, str_num in enumerate(str_nums):
            tmp += (10 ** i) * int(str_num)
        if tmp % 8 == 0:
            print("Yes")
            exit()
    print("No")
else:
    arr = [0 for _ in range(10)]
    for s in S:
        arr[int(s)] += 1
    # print(arr)
    # 下3桁
    for i in range(1, 125):
        tmp_arr = [0 for _ in range(10)]
        str_num = str(8 * i)
        tmp_arr[0] += (3 - len(str_num))
        for s in str_num:
            tmp_arr[int(s)] += 1
        # from IPython import embed; embed(); exit();
        tmp_flag = True
        for j in range(10):
            if tmp_arr[j] > arr[j]:
                tmp_flag = False
                break
        # print(str_num, tmp_flag)
        if tmp_flag:
            print("Yes")
            exit()
    print("No")
