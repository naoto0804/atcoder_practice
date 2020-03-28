import sys
print(sys.getrecursionlimit())
sys.setrecursionlimit(2000)
print(sys.getrecursionlimit())

H, W = list(map(int, input().split()))
rows = []
for i in range(H):
    row = input()
    rows.append(row)
    for j, r in enumerate(row):
        if r == 's':
            s_x, s_y = j, i
        elif r == 'g':
            g_x, g_y = j, i
        elif r == '.':
            pass

# import random
# H, W = 500, 500
# rows = []
# for i in range(H):
#     row = []
#     for j in range(W):
#         row.append(random.choices(['.', '#'], weights=[0.75, 0.25])[0])
#     rows.append(row)

# s_x, s_y = random.randint(0, W - 1), random.randint(0, H - 1)
# g_x, g_y = random.randint(0, W - 1), random.randint(0, H - 1)
# rows[s_y][s_x] = 's'
# rows[g_y][g_x] = 'g'

visited = [[False for _ in range(W)] for __ in range(H)]
direction = [[0, 1], [0, -1], [1, 0], [-1, 0]]
# DFS by recursive function
def search(x, y):
    if (not 0 <= x <= W - 1) or (not 0 <= y <= H - 1):
        return
    if visited[y][x]:
        return
    if rows[y][x] == '#':
        return

    visited[y][x] = True
    for (d_x, d_y) in direction:
        search(x + d_x, y + d_y)

search(s_x, s_y)
if visited[g_y][g_x]:
    print("Yes")
else:
    print("No")
