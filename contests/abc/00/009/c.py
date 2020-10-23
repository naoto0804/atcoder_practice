N, K = map(int, input().split())
S = list(input())
D = sorted(S)
ans = [""]*N


def check(D, d, S):
    S2 = S.copy()
    D2 = D.copy()
    D2.remove(d)
    for a in D2:
        try:
            S2.remove(a)
        except ValueError:
            pass
    return len(S2)


change = 0
for i in range(N):
    for d in D:
        if d == S[i]:
            ans[i] = d
            D.remove(d)
            break
        else:
            oth = check(D, d, S[i+1:])
            if change + 1 + oth > K:
                continue
            else:
                change += 1
                ans[i] = d
                D.remove(ans[i])
                break

print(*ans, sep="")
