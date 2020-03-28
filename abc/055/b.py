N = int(input())

power = 1
tmp = 1  # this is devided by 10^{9} + 7
prime = int(1e9 + 7)
for n in range(1, N + 1):
    tmp = tmp * n
    if tmp > prime:
        tmp = tmp % prime
print(tmp)
