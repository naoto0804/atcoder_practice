# https://atcoder.jp/contests/abc088/tasks/abc088_b
N = int(input())
arr = sorted(list(map(int, input().split())), reverse=True)
alice_total, bob_total = 0, 0

for i in range(len(arr)):
    if i % 2 == 0:
        alice_total += arr[i]
    else:
        bob_total += arr[i]
print(alice_total - bob_total)
