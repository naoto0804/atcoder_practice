N, X, Y = list(map(int, input().split()))
res = [0] * N
for j in range(1, N + 1):
    for i in range(1, j):
        res[min(j - i, abs(X - i) + abs(Y - j) + 1)] += 1

for i in range(1, N):
    print(res[i])
