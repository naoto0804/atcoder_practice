N, A, B = list(map(int, input().split()))
x = N // (A + B)
y = N % (A + B)

if y < A:
    print(x * A + y)
else:
    print(x * A + A)
