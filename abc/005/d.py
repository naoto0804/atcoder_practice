# https://atcoder.jp/contests/abc005/tasks/abc005_4
from collections import defaultdict
import numpy as np

N = int(input())
D = []
for i in range(N):
    D.append(list(map(int, input().split())))

Q = int(input())
P = []
for i in range(Q):
    P.append(int(input()))

acc_D =[[0 for _ in range(N + 1)] for __ in range(N + 1)]

for y in range(1, N + 1):
    for x in range(1, N + 1):
        acc_D[y][x] = acc_D[y][x - 1] + acc_D[y - 1][x] - acc_D[y - 1][x - 1] + D[y - 1][x - 1]


def get_score(ymin, ymax, xmin, xmax):  # time O(1)
    return acc_D[ymax + 1][xmax + 1] - acc_D[ymax + 1][xmin] - acc_D[ymin][xmax + 1] + acc_D[ymin][xmin]

max_score_dict = defaultdict(int)  # key: area, value: score of best rectangle by time O(N^4)
for ymin in range(N):
    for ymax in range(N):
        if ymax < ymin:
            continue
        for xmin in range(N):
            for xmax in range(N):
                if xmax < xmin:
                    continue
                area = (ymax - ymin + 1) * (xmax - xmin + 1)
                score = get_score(ymin, ymax, xmin, xmax)
                current_max = max_score_dict.get(area)
                if current_max and score < current_max:
                    continue
                else:
                    max_score_dict[area] = score

score_dict = {}
for i in range(1, N * N + 1):  # time O(N^2)
    if i == 1:
        score = max_score_dict[i]
        prev_max = score
    else:
        score = max_score_dict.get(i)
        if score and score > prev_max:
            prev_max = score
    score_dict[i] = prev_max

for p in P:
    print(score_dict[p])
# from IPython import embed; embed(); exit();
