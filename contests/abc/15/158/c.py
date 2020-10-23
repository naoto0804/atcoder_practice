A, B = list(map(int, input().split()))
ans = -1
for i in range(1, 1010):
    a = int(i * 0.08)
    b = int(i * 0.1)
    if a == A and b == B:
        ans = i
        break
print(ans)
