characters = input()
N = len(characters)

total = 0
for i in range(2 ** (N - 1)):
    operation = ""
    for j in range(N - 1):
        operation += characters[j]
        if ((i >> j) & 1):
            operation += "+"
    operation += characters[N - 1]
    ans = eval(operation)
    total += ans
print(total)
