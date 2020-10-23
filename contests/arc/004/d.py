mod = 10**9+7
def prime(n,p):
    iteral = 0
    while n%p == 0:
        n //= p
        iteral += 1
    return iteral,n
def modpow(a,n):#二乗
    if n==0:
        return 1
    elif n==1:
        return a%mod
    elif n%2==0:
        return (modpow(a,n/2)**2)%mod
    else:
        return (a*modpow(a,n-1))%mod
 
def modfact(l,r):#階乗
    fact=1
    for i in range(l-r+1):
        fact=fact*(r+i)%mod
    return fact
 
def comb(n,x):#組み合わせ
    S=modfact(n,n-x+1)
    fact=modfact(x,1)
    T=modpow(fact,mod-2)
    return S*T%mod
def main():
    N,M = map(int,input().split())
    N = abs(N)
    ans = (2**M)//2%mod
    for p in range(2,int(N**0.5)+1000):
        if N%p==0:
            iteral,N = prime(N,p)
            ans *= comb(iteral+M-1,iteral)
            ans %= mod
    if N > 1:
        ans = ans*M%mod
    print(ans%mod)

if __name__ == "__main__":
    main()
