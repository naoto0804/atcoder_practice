// ctrl+shift+b
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

ll mod_inverse(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

void Main() {
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N){cin >> A.at(i);}
    ll A_sum = 0;
    rep(i, N){A_sum = (A_sum + A.at(i)) % MOD;}
    ll A_prod = 0;
    rep(i, N){A_prod = (A_prod + A.at(i) * A.at(i) % MOD) % MOD;}
    ll ans = (A_sum * A_sum % MOD - A_prod) % MOD * mod_inverse(2, MOD) % MOD;
    if (ans < 0){
        cout << ans + MOD << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
