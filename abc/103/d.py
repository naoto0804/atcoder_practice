import numpy as np
from collections import defaultdict
N, M = list(map(int, input().split()))

edge_dict = defaultdict(set)
A, B = [], []
for i in range(M):
    a, b = list(map(int, input().split()))
    A.append(a)
    B.append(b)
A = np.array(A)
B = np.array(B)
inds = np.argsort(B)

last_connected_node = 0
cnt = 0
for a, b in zip(A[inds], B[inds]):
    if last_connected_node <= a:
        last_connected_node = b  # separate between b - 1 and b
        cnt += 1
print(cnt)
