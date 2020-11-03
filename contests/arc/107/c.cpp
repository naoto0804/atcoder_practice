// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll> >;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 998244353;
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


void Main() {
    combination_init();

    ll N, K; cin >> N >> K;
    dsu row_d(N), col_d(N);
    ll arr[N][N];
    rep(i, N){rep(j, N){cin >> arr[i][j];}}

    rep(i, N){rep(j, N){
        if (i >= j){continue;}
        bool flag = true;
        rep(k, N){if (arr[i][k] + arr[j][k] > K){flag = false;}}
        if (flag){row_d.merge(i, j);}
    }}

    rep(i, N){rep(j, N){
        if (i >= j){continue;}
        bool flag = true;
        rep(k, N){if (arr[k][i] + arr[k][j] > K){flag = false;}}
        if (flag){col_d.merge(i, j);}
    }}

    // for (auto g: row_d.groups()){cout << g.size() << endl;}
    // for (auto g: col_d.groups()){cout << g.size() << endl;}
    ll ans = 1;
    for (auto g: row_d.groups()){ans = ans * factorial(g.size()) % MOD;}
    for (auto g: col_d.groups()){ans = ans * factorial(g.size()) % MOD;}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
