S = input()

ind = (len(S) + 1) // 2

left = S[:ind-1]
right = S[ind:]

def check(x):
    if len(x) % 2 == 0:
        ind = len(x) // 2
        if x[:ind] == x[ind:][::-1]:
            return True
        else:
            return False
    else:
        ind = (len(x) + 1) // 2
        if x[:ind-1] == x[ind:][::-1]:
            return True
        else:
            return False

if check(S) and check(left) and check(right):
    print("Yes")
else:
    print("No")
