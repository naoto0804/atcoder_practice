def MAP(): return map(int, input().split())
def ZIP(n): return zip(*(MAP() for _ in range(n)))

N = int(input())
AB = ZIP(N - 1)

from IPython import embed; embed(); exit();