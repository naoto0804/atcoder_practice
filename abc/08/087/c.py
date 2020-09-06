import numpy as np

N = int(input())
scores = np.zeros((2, N))
sum_max_scores = np.zeros((2, N))

for i in range(2):
    # rows.append(list(map(int, input().split())))
    for j, num in enumerate(map(int, input().split())):
        scores[i][j] = num

for j in range(N):
    for i in range(2):
        if i == 0:
            if j == 0:
                sum_max_scores[0][0] = scores[0][0]
            else:
                sum_max_scores[i][j] = sum_max_scores[i][j-1] + scores[i][j]
        else:
            if j == 0:
                sum_max_scores[i][j] = scores[1][0] + sum_max_scores[0][0]
            else:
                sum_max_scores[i][j] = \
                    max(
                        sum_max_scores[i][j-1] + scores[i][j],
                        sum_max_scores[i-1][j] + scores[i][j]
                    )
print(int(sum_max_scores[-1][-1]))
