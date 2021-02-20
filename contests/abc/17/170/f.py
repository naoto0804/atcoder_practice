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

# 1~Kにエッジを貼ると一気に計算量が破裂するので
# コスト1で隣接edgeだけ保持して，方向転換する時にKの倍数に切り上げる工夫をする
H, W, K = list(MAP())
coords = [x - 1 for x in list(MAP())]
start, end = coords[:2], coords[2:]
board = [[True for j in range(W)] for i in range(H)]
for i in range(H):
    s = input()
    for j in range(W):
        if s[j] == "@":
            board[i][j] = False

q = []
heappush(q, (0, start, (0, 0)))  # (cost, pos, vec)

costs = [[INF for j in range(W)] for i in range(H)]
costs[start[0]][start[1]] = 0

while len(q) > 0:
    cost, (y, x), (dy, dx) = heappop(q)

    if cost > costs[y][x]:
        continue

    for (new_dy, new_dx) in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
        new_y, new_x = y + new_dy, x + new_dx
        if new_y < 0 or new_x < 0 or new_y >= H or new_x >= W or not board[new_y][new_x]:
            continue
        if (dy, dx) == (new_dy, new_dx):
            new_cost = cost + 1
        else:
            new_cost = ceil(cost / K) * K + 1

        if new_cost < costs[new_y][new_x]:
            costs[new_y][new_x] = new_cost
            heappush(q, (new_cost, (new_y, new_x), (new_dy, new_dx)))
ans = costs[end[0]][end[1]]
if ans == INF:
    print(-1)
else:
    print(ceil(ans / K))
