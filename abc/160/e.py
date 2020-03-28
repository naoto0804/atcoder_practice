X, Y, A, B, C = list(map(int, input().split()))
P = sorted(list(map(int, input().split())), reverse=True)[:X]
Q = sorted(list(map(int, input().split())), reverse=True)[:Y]
R = sorted(list(map(int, input().split())), reverse=True)  # 降順=入れたい順

cands = sorted(P + Q)  # 昇順=消して欲しい順

c_ind = 0
r_ind = 0

while True:
    if c_ind >= len(cands) or r_ind >= len(R):
        break
    c = cands[c_ind]
    r = R[r_ind]
    if c >= r:
        break
    else:
        c_ind += 1
        r_ind += 1

print(sum(cands[c_ind:]) + sum(R[:r_ind]))
