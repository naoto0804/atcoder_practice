N, M = list(map(int, input().split()))
relation = dict()
max_num = -1
for i in range(M):
    x1, y1 = input().split()
    relation[x1 + '&' + y1] = True # register relation as key

for i in range(2 ** N):
    sub_group = []
    for j in range(N):
        if ((i >> j) & 1):
            sub_group.append(str(j + 1))

    flag = True
    for j, s1 in enumerate(sub_group):
        for k, s2 in enumerate(sub_group):
            if k <= j:
                continue
            if not relation.get(s1 + '&' + s2):
                flag = False
                break
        if not flag:
            break

    if flag:
        num = len(sub_group)
        if max_num < num:
            max_num = num
print(max_num)
