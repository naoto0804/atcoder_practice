arr = input()
cnt = 0
for a in arr:
    if a == 'A':
        cnt += 1

if cnt == 0 or cnt == len(arr):
    print("No")
else:
    print("Yes")
