from collections import defaultdict
N = int(input())

cnt_dict = defaultdict(int)
for a in map(int, input().split()):
    cnt_dict[a] += 1

n_unique = len(cnt_dict.keys())

if (N - n_unique) % 2 == 0:
    print(n_unique)
else:
    print(n_unique - 1)
