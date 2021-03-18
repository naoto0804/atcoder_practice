import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import accumulate, permutations, combinations, product
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
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

N=int(input())
S=[int(x) for x in list(input())]
X=input()
dp=[[False for j in range(7)]for i in range(N+1)]
dp[N][0]=True

# 後ろからDP
# dp[i] = 次の条件を満たす数rの集合
# iラウンド目が終了した時点でTを7で割ったあまりがrであるときここからゲームを続けると高橋君が勝つ
dp = [set() for _ in range(N + 1)]
dp[-1].add(0)

for i in range(N-1,-1,-1):
    for j in range(7):
        a0=j*10%7
        a1=(10*j+S[i])%7
        if X[i]=="A":
            if dp[i+1][a0] and dp[i+1][a1]:
                dp[i][j]=True
            else:
                dp[i][j]=False
        elif X[i]=="T":
            if dp[i+1][a0] or dp[i+1][a1]:
                dp[i][j]=True
            else:
                dp[i][j]=False
        else:
            assert False
if dp[0][0]:
    print("Takahashi")
else:
    print("Aoki")
