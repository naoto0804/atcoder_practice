H, W = list(map(int, input().split()))
rows = []
for i in range(H):
    rows.append(input())

flag = True
output_rows = [['#' for _ in range(W)] for __ in range(H)]

for i in range(H):
    for j in range(W):
        if rows[i][j] != '#':
            continue
        else:
            found = False
            for (dx, dy) in [[0, -1], [0, 1], [-1, 0], [1, 0]]:
                y, x = i + dy, j + dx
                if x < 0 or x > W - 1 or y < 0 or y > H - 1:
                    continue
                else:
                    if rows[y][x] == '#':
                        found = True
            if not found:
                flag = False
                break

if flag:
    print("Yes")
else:
    print("No")
