# https://atcoder.jp/contests/agc023/tasks/agc023_a

from collections import defaultdict
N = input()
A = list(map(int, input().split()))

acc_sum_dict = defaultdict(int)
acc_sum_dict[0] += 1
acc_sum = 0

cnt = 0
for a in A:
    acc_sum += a
    if acc_sum_dict.get(acc_sum):
        cnt += acc_sum_dict[acc_sum]
    acc_sum_dict[acc_sum] += 1
print(cnt)
