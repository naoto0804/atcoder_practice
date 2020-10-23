Q = int(input())
N = int(10e5)

queries = []

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

prime_numbers_list = set(get_all_prime_numbers(N))

accum_sum = [0]  # should contain accumulated sum for [], [1], [1, 3], [1, 3, 5], ...
for i in range(N // 2):
    num = 2 * i + 1
    if num in prime_numbers_list and (num + 1) // 2 in prime_numbers_list:
        accum_sum.append(accum_sum[-1] + 1)
    else:
        accum_sum.append(accum_sum[-1])

for i in range(Q):
    l, r = list(map(int, input().split()))
    l_ind, r_ind = (l + 1) // 2, (r + 1) // 2
    print(accum_sum[r_ind] - accum_sum[l_ind - 1])
