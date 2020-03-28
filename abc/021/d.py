# 非常に簡単な重複組合せ

# nCr mod m
# rがn/2に近いと非常に重くなる
def combination(n, r, mod=10**9+7):
    n1, r = n+1, min(r, n-r)
    numer = denom = 1
    for i in range(1, r+1):
        numer = numer * (n1-i) % mod
        denom = denom * i % mod
    return numer * pow(denom, mod-2, mod) % mod

# nHr mod m
def H(n, r, mod=10**9+7):
    return combination(n+r-1, r, mod)

n = int(input())
k = int(input())

# n個の中から重複を許してk個の数を選ぶ組み合わせ
# = k個の丸とn-1個の棒を一列に配置する組み合わせn+k-1Ck
print(H(n, k))
