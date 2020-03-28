# https://atcoder.jp/contests/abc075/tasks/abc075_b

# import random
# H, W = 50, 50
# rows = [[random.choice(['#', '.']) for _ in range(W)] for __ in range(H)]


H, W = list(map(int, input().split()))
rows = []
for i in range(H):
    rows.append(input())

output_rows = [['#' for _ in range(W)] for __ in range(H)]

for i in range(H):
    for j in range(W):
        if rows[i][j] == '#':
            continue
        else:
            total = 0
            for dy in range(-1, 1 + 1):
                for dx in range(-1, 1 + 1):

                    y, x = i + dy, j + dx
                    if x < 0 or x > W - 1 or y < 0 or y > H - 1:
                        continue
                    else:
                        if rows[y][x] == '#':
                            total += 1
            output_rows[i][j] = str(total)

for i in range(H):
    print("".join(output_rows[i]))

