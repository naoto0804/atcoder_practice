import math
from collections import defaultdict
N, M = list(map(int, input().split()))
MOD = 10 ** 9 + 7

def get_all_prime_numbers(N):
    values = list(range(1, N + 1))
    flags = [1] * N
    flags[0] = 0  # delete 1
    for i in range(N):
        if flags[i] == 0:
            continue

        prime = values[i]
        for mult in range(2, N // prime + 1):
            cand = mult * prime
            if flags[cand - 1] == 1:
                flags[cand - 1] = 0

    prime_numbers = []
    for i in range(N):
        if flags[i] == 1:
            prime_numbers.append(values[i])
    return prime_numbers

def prime_factorization(N):  # O(N ** 0.5)
    prime_count_dict = defaultdict(int)
    tmp = N
    # N の素因数はたかだか N^{1/2}以下なので実はかなり早く取れるはず
    for n in get_all_prime_numbers(int(N ** 0.5) + 1):
        while True:
            if tmp % n == 0:
                tmp = tmp / n
                prime_count_dict[n] += 1
            else:
                break
    return prime_count_dict

def combination(a, b):  # pick only b elements from a elements
    b_ = min([b, a - b])
    print(a, b)
    ans = 1
    for i in range(b_):
        print(a - i, b_ - i)
        ans *= a - i
        ans /= b_ - i
    return ans
    # return ans // math.factorial(b_)
    # this may result in multiplying too big numbers..
    # return int(math.factorial(a) / (math.factorial(b) * math.factorial(a - b)))

result = prime_factorization(M)

ans = 1
for v in result.values():
    ans *= combination(v + N - 1, N - 1)
    ans %= MOD
print(int(ans))
