# 再帰以外の場合はpypy3を使うといい
# https://qiita.com/OKCH3COOH/items/f0c5c4681bc30dddf7f4
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


def get_num(chars, char_dict):
    ans = 0
    for i, c in enumerate(chars):
        ans = ans * 10
        if c.isdigit():
            num = c
        else:
            num = char_dict[c]
        # 最高位0対策
        if i == 0 and num == 0:
            return None
        ans += num
    return ans


sall = []
s1 = input()
s2 = input()
s3 = input()
for s in [s1, s2, s3]:
    sall.extend(list(s))
char_counter = Counter(sall)
C = len(char_counter.keys())
if C > 10:
    print("UNSOLVABLE")
else:
    cnt = 0
    for data in combinations(range(10), C):
        for p in permutations(data):
            cnt += 1
            char_dict = {k:v for (k, v) in zip(char_counter.keys(), p)}
            n1, n2, n3 = get_num(s1, char_dict), get_num(s2, char_dict), get_num(s3, char_dict)
            if n1 and n2 and n3 and n1 + n2 == n3:
                print(n1)
                print(n2)
                print(n3)
                exit()
    print("UNSOLVABLE")
