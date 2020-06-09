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
    ll N, D; cin >> N >> D;
    ll X[N][D];
    rep(i, N){rep(j, D){
        cin >> X[i][j];
    }}
    ll ans = 0;
    rep(i, N){rep(j, N){
        if (i >= j){
            continue;
        } else {
            ll tmp = 0;
            rep(k, D){tmp += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);}
            // イコールで判定するのは誤差が怖いので，最寄りの整数に十分近ければOKとする
            if (abs(round(sqrt(tmp)) - sqrt(tmp)) < 1e-6){ans++;}
        }
    }}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
