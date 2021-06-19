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

#bit全探索(python)
for i in range(2 ** N):
    string = ""
    tmp = 0
    for j in range(N):
        if ((i >> j) & 1):
            string += "("
        else:
            string += ")"

    # 典型
    # ( -> +1, ) -> -1 で，累積が途中で常にプラスかつ全部足し合わせたときに0
    # (本筋は) stackで (が出たらappend, )が出たらpopして整合性チェック
    nums = [0]
    flag = True
    for s in string:
        add = 1 if s == "(" else -1
        num = nums[-1] + add
        if num < 0:
            flag = False
            break
        nums.append(num)

    if nums[-1] == 0 and flag:
        print(string)
