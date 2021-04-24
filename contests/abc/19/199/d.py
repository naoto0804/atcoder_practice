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

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())


def search(arr, adj_edge_list, depth):
    if depth == N:
        return 1

    ans = 0

    # 隣接行列をチェック
    adj_colors = []
    for e in adj_edge_list[depth]:
        adj_colors.append(arr[e])
    adj_colors = set(adj_colors)
    valid_colors = colors.difference(adj_colors.difference(dummy))

    # バックトラック
    for c in valid_colors:
        arr[depth] = c
        ans += search(arr, adj_edge_list, depth + 1)
        arr[depth] = None
    return ans


N, M = list(MAP())
edge_list = [[] for _ in range(N)]
uf = UnionFind(N)
for i in range(M):
    a, b = list(MAP())
    a, b = a - 1, b - 1
    edge_list[a].append(b)
    edge_list[b].append(a)
    uf.union(a, b)

dummy = set([None])
colors = set(['r', 'g', 'b'])

# union-find木の解で分割して捜索
ans_list = []
for indices in uf.all_group_members().values():
    g_N = len(indices)
    g_arr = [None for _ in range(g_N)]
    ind_dict = {ind: i for i, ind in enumerate(indices)}
    g_edge_list = [[] for _ in range(g_N)]

    for old_ind in indices:
        new_ind = ind_dict[old_ind]
        g_edge_list[new_ind] = [ind_dict[e] for e in edge_list[old_ind]]
    if g_arr == [None] and g_edge_list == [[]]:
        ans_list.append(3)
    else:
        ans_list.append(search(g_arr, g_edge_list, 0))

ans = 1
for a in ans_list:
    ans *= a
print(ans)
