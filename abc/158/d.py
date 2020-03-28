from collections import deque

string = input()
x = deque()
for s in string:
    x.append(s)

head_left = True
B = int(input())
for i in range(B):
    cmd = input().split()
    if len(cmd) == 1 and cmd[0] == "1":
        head_left = not head_left
    else:
        _, n, c = cmd
        if (n == "1" and head_left) or (n == "2" and not head_left):
            x.appendleft(c)
        else:
            x.append(c)

if head_left:
    print("".join(list(x)))
else:
    print("".join(reversed(list(x))))
