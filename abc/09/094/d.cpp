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


void Main() {
    // a1は大きければ大きいほど良く，a2は[n/2]に近いほどよい
    // (n+1)Cr >> (n+1)Cr (これは帰納的に使える)
    ll n; cin >> n;
    vector<ll> a(n); rep(i, n){cin >> a.at(i);}
    sort(a.begin(), a.end(), greater<ll>()); // 昇順 ascending
    ll a_i = a.at(0);
    ll diff = 0;
    ll ans = 0;
    rep(i, n){
        ll tmp = min(a.at(i), a_i - a.at(i));
        if (tmp > diff){diff = tmp; ans = a.at(i);}
    }
    cout << a_i << " " << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
