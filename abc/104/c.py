import math
D, G = list(map(int, input().split()))

arr = []
for i in range(1, D + 1):
    p, c = list(map(int, input().split()))
    arr.append([i * 100, p, c])

min_n_solved_problems = 1e100
for i in range(2 ** D):
    solved_flag = [False] * D
    score = 0
    n_solved_problems = 0
    for j in range(D):
        if ((i >> j) & 1):
            solved_flag[j] = True
            point, num, bonus = arr[j]
            score += point * num + bonus
            n_solved_problems += num
        else:
            biggest_unsolved_ind = j

    if score < G:
        point, num, bonus = arr[biggest_unsolved_ind]
        n_add = math.ceil((G - score) / arr[biggest_unsolved_ind][0])
        if n_add > num - 1: # If we use num - 1 of the biggest one and still cannot reach, it's not the case
            continue
        score += n_add * point
        n_solved_problems += n_add

    if min_n_solved_problems > n_solved_problems:
        min_n_solved_problems = n_solved_problems
print(min_n_solved_problems)
