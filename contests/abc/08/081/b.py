N = int(input())
arr = list(map(int, input().split()))

cnt = 0
flag = False
while True:
    for a in arr:
        if a == 0 or a == 1 or a % 2 == 1:
            flag = True
            break

    if flag:
        break

    arr = [a // 2 for a in arr]
    cnt += 1

print(cnt)
