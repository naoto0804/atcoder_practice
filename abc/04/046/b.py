import math

N, K = list(map(int, input().split()))
print(int(K * math.pow(K - 1, N - 1)))
