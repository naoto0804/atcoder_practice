import numpy as np
from itertools import product


H, W, K = list(map(int, input().split()))
board = np.zeros((H + 1, W + 1))
for i in range(H):
    string = input()
    for j in range(W):
        if string[j] == '1':
            board[i + 1][j + 1] = 1

acc_board = board.cumsum(axis=0).cumsum(axis=1)

def score(ymin, ymax, xmin, xmax):
    total = 0
    total += acc_board[ymin, xmin]
    total += acc_board[ymax, xmax]
    total -= acc_board[ymin, xmax]
    total -= acc_board[ymax, xmin]
    return total

if np.sum(board) <= K:
    print(0)
    exit()
else:
    # for i in range(1, H * W + 1):
    #     for n_y in range(0, i + 1):
    #         n_x = i - n_y
    #         print(i, n_x, n_y)
    #         for yinds, xinds in zip(combinations(range(H - 1), n_x), combinations(range(W - 1), n_y)):
    #             from IPython import embed; embed(); exit();
    separation_w = list(product([0, 1], repeat=W-1))
    separation_h = list(product([0, 1], repeat=H-1))

    sep_list = []
    for sep in separation_h:
        # left_ind = 0
        # right_ind = H
        if sum(sep) == 0:
            sep_list.append([(0, H)])
        else:
            from IPython import embed; embed(); exit();
