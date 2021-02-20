X = [int(i) for i in input()]
M = int(input())

d = max(X)
if len(X) < 2:
    print(int(d <= M))
    quit()

# 二分探索バリエーションその2
ng, ok = 10 ** 18 + 10, 0
while abs(ok - ng) > 1:
    mid = (ok + ng) // 2

    res = 0
    cur = 1
    for x in reversed(X):
        res += cur * x
        cur *= mid

    if res <= M:
        ok = mid
    else:
        ng = mid

print(max(0, ok - d))
