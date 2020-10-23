# https://atcoder.jp/contests/abc049/tasks/arc065_a

txt = input()
cands = ["dream", "dreamer", "erase", "eraser"]

success = True
while len(txt) > 0:
    flag = False

    for cand in cands:
        subtxt = txt[len(txt) - len(cand):]
        if subtxt == cand:
            txt = txt[:len(txt) - len(cand)]
            flag = True
            break

    if not flag:
        success = False
        break

if success:
    print("YES")
else:
    print("NO")
