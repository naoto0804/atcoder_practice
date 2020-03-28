# https://atcoder.jp/contests/abc083/tasks/abc083_b
N, A, B = list(map(int, input().split()))

def get_sum(n):
    ans = 0
    while True:
        ans += n % 10
        if n // 10 > 0:
            n = n // 10
        else:
            break
    return ans

total = 0
for i in range(1, N + 1):
    ans = get_sum(i)
    if A <= ans <= B:
        total += i
print(total)
