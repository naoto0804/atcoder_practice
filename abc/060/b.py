A, B, C = list(map(int, input().split()))

flag = False
for i in range(1, B + 1):
    remainder = A * i % B
    if remainder == C:
        flag = True
if flag:
    print("Yes")
else:
    print("No")
