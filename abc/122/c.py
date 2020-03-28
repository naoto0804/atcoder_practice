N, Q = list(map(int, input().split()))
S = input()

flags = [0] * N
for i in range(N):
    if i != 0 and S[i - 1:i + 1] == 'AC':
        flags[i] = 1

acc_sum = [0] * N
for i in range(1, N):
    if flags[i] == 1:
        acc_sum[i] = acc_sum[i - 1] + 1
    else:
        acc_sum[i] = acc_sum[i - 1]

for i in range(Q):
    l, r = list(map(int, input().split()))
    if l == r:
        print(0)
    else:
        print(acc_sum[r - 1] - acc_sum[l - 1])
