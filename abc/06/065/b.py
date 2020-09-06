import math
from collections import defaultdict

N = int(input())
a = defaultdict(list)
for i in range(1, N + 1):
    a[int(input())].append(i)

def check(key):
    # print(key)
    if key == 1:  # find goal
        return 1
    elif key == 2:  # forming infinite loop
        return math.inf
    else:
        values = a[key]
        if len(values) == 0:
            return math.inf
        return min([check(v) for v in values]) + 1

if a.get(2):
    ans = min([check(v) for v in a[2]])
else:
    ans = math.inf

if ans == math.inf:
    print(-1)
else:
    print(ans)
