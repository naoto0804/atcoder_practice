N = int(input())
times = []
for i in range(N):
    times.append(int(input()))

min_time = 1e10
for i in range(2 ** N):
    roaster_1_time = 0
    roaster_2_time = 0
    for j in range(N):
        if ((i >> j) & 1):
            roaster_1_time += times[j]
        else:
            roaster_2_time += times[j]
    time = max(roaster_1_time, roaster_2_time)
    if time < min_time:
        min_time = time
print(min_time)
