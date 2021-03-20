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
import numpy as np
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

def check(arr):
    h, w = len(arr), len(arr[0])
    for i in range(h):
        for j in range(w):
            if not arr[i][j]:
                return False
    return True

H, W, A, B = list(MAP())
init_board = [[False for _ in range(W)] for _ in range(H)]
coords = list(product(range(H), range(W)))

# DFS, 典型的なbacktrack問題(DFSはちゃんと捜査をundoするのが面倒だがboardを保持しない分圧倒的にメモリ節約になる)
def search(board, depth, a, b):
    if a < 0 or b < 0: return 0
    if check(board) and a == 0 and b == 0: return 1

    ans = 0
    y, x = coords[depth][0], coords[depth][1]

    if board[y][x]:  # 埋まっているときはスルー
        ans += search(board, depth + 1, a, b)
    else:
        # try 1x1
        board[y][x] = True
        ans += search(board, depth + 1, a, b - 1)
        board[y][x] = False

        # try 2x1
        if y - 1 >= 0 and not board[y][x] and not board[y - 1][x]:
            board[y][x], board[y - 1][x] = True, True
            ans += search(board, depth + 1, a - 1, b)
            board[y][x], board[y - 1][x] = False, False

        if y + 1 < H and not board[y][x] and not board[y + 1][x]:
            board[y][x], board[y + 1][x] = True, True
            ans += search(board, depth + 1, a - 1, b)
            board[y][x], board[y + 1][x] = False, False

        if x - 1 >= 0 and not board[y][x] and not board[y][x - 1]:
            board[y][x], board[y][x - 1] = True, True
            ans += search(board, depth + 1, a - 1, b)
            board[y][x], board[y][x - 1] = False, False

        if x + 1 < W and not board[y][x] and not board[y][x + 1]:
            board[y][x], board[y][x + 1] = True, True
            ans += search(board, depth + 1, a - 1, b)
            board[y][x], board[y][x + 1] = False, False

    return ans

print(search(init_board, 0, A, B))
