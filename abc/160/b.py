X = int(input())
ans = 0
ans += (X // 500) * 1000
res = X % 500
ans += (res // 5) * 5
print(ans)
