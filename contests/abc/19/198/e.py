# コスト1かつ構造が木なのでDFSでも最短経路が一意に定まる

import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, floor, log10
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
C = list(MAP())
edges = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = list(MAP())
    a -= 1
    b -= 1
    edges[a].append(b)
    edges[b].append(a)
visited = [False for _ in range(N)]
ans = [False for _ in range(N)]

def valid_keys(dic):
    return [k for k in dic.keys() if dic[k] > 0]


# DFS, 典型的なbacktrack問題(DFSはちゃんとundoするのが面倒だがややこし目の中間変数を全保持しない分圧倒的にメモリ節約になる)
def search(ind, color_dic, visited):
    if visited[ind]:
        return
    else:
        # preprocess
        visited[ind] = True
        if color_dic[C[ind]] == 0:
            ans[ind] = True
        color_dic[C[ind]] += 1

        for new_ind in edges[ind]:
            search(new_ind, color_dic, visited)

        # postprocess
        visited[ind] = False
        color_dic[C[ind]] -= 1

search(ind=0, color_dic=defaultdict(int), visited=[False for _ in range(N)])

for i, a in enumerate(ans):
    if a: print(i + 1)
