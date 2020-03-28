s = input()
t = input()
memo = []
 
for i in range(len(s)-len(t)+1):
    p = s[i:(i+len(t))]
    flag = True
    for j in range(len(t)):
        if p[j] != "?" and p[j] != t[j]:
            flag = False
            break
    if flag:
        memo.append((s[0:i]+t+s[(i+len(t)):len(s)]).replace("?","a"))
 
if len(memo) == 0:
    print("UNRESTORABLE")
else:
    print(min(memo))