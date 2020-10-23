# https://atcoder.jp/contests/abc085/tasks/abc085_b
N = int(input())
unique_arr = set()
for i in range(N):
    unique_arr.add(int(input()))
print(len(unique_arr))
