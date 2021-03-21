# 一番小さいXから2倍ごとに大きくしていくのが自明に最小？
X, Y = list(map(int, input().split()))

cnt = 1
x = X
while True:
    x = 2 * x
    if x > Y:
        break
    cnt += 1
print(cnt)
