N = int(input())

points = []
for i in range(N):
    points.append(list(map(int, input().split())))

dist_min = -1
for i in range(N):
    for j in range(i + 1, N):
        p1_x, p1_y = points[i]
        p2_x, p2_y = points[j]
        dist = ((p1_x - p2_x) ** 2 + (p1_y - p2_y) ** 2) ** 0.5
        if dist > dist_min:
            dist_min = dist
print(dist_min)
