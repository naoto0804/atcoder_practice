# https://atcoder.jp/contests/abc083/tasks/abc085_c
N, Y = list(map(int, input().split()))
final_ans = None
for i in range(N + 1):
    for j in range(N + 1):
        if i + j > N:
            continue
        ans = i * 10000 + j * 5000 + (N - i - j) * 1000
        if ans == Y:
            final_ans = " ".join([str(i), str(j), str(N - i - j)])
            break

if final_ans is None:
    print('-1 -1 -1')
else:
    print(final_ans)
