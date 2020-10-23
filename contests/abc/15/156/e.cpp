#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
bool initialized = false;

/**
 * @fn
 * This function must be called at first.
 */
void combination_init() {
    initialized = true;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

/**
 * @fn
 * Calculates the combination  ( nCK % p: N choose K mod p).
 *
 * @brief constraint: 1 ≤ k ≤ n ≤ 10^7
 * @return nCK % MOD
 */
long long combination(int n, int k) {
    assert(initialized);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/**
 * @fn
 * Calculates the factorial of the number.
 *
 * @return N! % MOD
 */
long long factorial(int n) {
    assert(initialized);
    if (n < 0) return 0;
    return fac[n] % MOD;
}

/**
 * @fn
 * Calculates the combination ( nCK % p: N choose K mod p).
 *
 * @brief constraint: 1 ≤ k ≤ 10^7 and 1 ≤ n ≤ 10^9
 * @return nCK % MOD
 */
long long combination2(int n, int k) {
    assert(initialized);
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    ll res = 1;
    k = min(k, n - k);
    for (long long x = 1; x <= k; x++) {
        res *= (n - x + 1);
        res %= MOD;
        res *= inv[x];
        res %= MOD;
    }
    return res;
}

long long ADD(long long x, long long y) { return (x+y) % MOD; }
long long SUB(long long x, long long y) { return (x-y+MOD) % MOD; }
long long MUL(long long x, long long y) { return x*y % MOD; }
long long POW(long long x, long long e) { long long v=1; for(; e; x=MUL(x,x), e>>=1) if (e&1) v = MUL(v,x); return v; }
long long DIV(long long x, long long y) { /*assert(y%MOD!=0);*/ return MUL(x, POW(y, MOD-2)); }

// ポイント: n回移動できるなら，n回移動でようやく出来るようになった組み合わせに加えて，0~n-1回移動で出来た組み合わせは必ず出来る
void Main() {
    combination_init();
    int n, k;
    cin >> n >> k;
    ll cnt[n], sum_cnt[n];
    rep(i, n){ // 空室の数は0~n-1
        if (i == 0){cnt[0] = 1; sum_cnt[0] = 1;} // 移動しない
        else {
            // nCm \times n-mHm = nCm \times n-1Cm
            cnt[i] = MUL(combination2(n, i), combination2(n - 1, i));
            sum_cnt[i] = ADD(sum_cnt[i - 1], cnt[i]);
        }
    }
    if (k > n - 1){cout << sum_cnt[n - 1] << endl;} else {cout << sum_cnt[k] << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
