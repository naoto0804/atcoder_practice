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
    ll N, M, Q; cin >> N >> M >> Q;
    vector<ll> p(Q), q(Q);

    // L, Rを二次元座標として，二次元累積和(長方形の差し引き)
    ll a[N][N]; rep(i, N){rep(j, N){a[i][j] = 0;}}
    ll s[N + 1][N + 1]; rep(i, N + 1){rep(j, N + 1){s[i][j] = 0;}}

    rep(i, M){ll l, r; cin >> l >> r; l--; r--; a[l][r]++;}
    rep(i, Q){cin >> p.at(i) >> q.at(i);}

    rep(i, N){rep(j, N){
        s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
    }}
    // rep(i, N + 1){rep(j, N + 1){cout << s[i][j] << " ";} cout << endl;}
    rep(i, Q){
        ll l = p.at(i) - 1, r = q.at(i);
        cout << s[r][r] + s[l][l] - s[r][l] - s[l][r] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
