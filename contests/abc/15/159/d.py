from collections import defaultdict

N = int(input())
A = list(map(int, input().split()))

cnt_dict = defaultdict(int)
for a in A:
    cnt_dict[a] += 1

total = 0
for v in cnt_dict.values():
    total += v * (v - 1) // 2

for a in A:
    print(total - (cnt_dict[a] - 1))
