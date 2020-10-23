import math


def validate(src_point, tgt_point, duration):
    s_x, s_y = src_point
    t_x, t_y = tgt_point

    if not 0 <= s_x <= 1e5: return False
    if not 0 <= s_y <= 1e5: return False
    if not 0 <= t_x <= 1e5: return False
    if not 0 <= t_y <= 1e5: return False

    dist = math.fabs(t_x - s_x) + math.fabs(t_y - s_y)

    if duration % 2 == 1:
        if dist <= duration and dist % 2 == 1:
            return True
        else:
            return False
    else:
        if dist <= duration and dist % 2 == 0:
            return True
        else:
            return False

N = int(input())
# src_point = (0, 0)
prev_point = (0, 0)
prev_time = 0

flag = True
for i in range(N):
    cur_time, *cur_point = list(map(int, input().split()))

    if not validate(prev_point, cur_point, cur_time - prev_time):
        flag = False
        break

    prev_time = cur_time
    prev_point = cur_point
if flag:
    print("Yes")
else:
    print("No")
