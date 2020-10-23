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
    ll N, C; cin >> N >> C;
    ll D[C][C], c[N][N];
    rep(i, C){rep(j, C){cin >> D[i][j];}}
    rep(i, N){rep(j, N){cin >> c[i][j]; c[i][j]--;}}

    ll ans = INF;
    // mod0, mod1, mod2にどの色を割り当てるかを全列挙していく (30 * 29 * 28)
    rep(i, C){rep(j, C){rep(k, C){
        if (i == j || j == k || i == k){continue;}

        ll cand = 0;
        rep(y, N){rep(x, N){
            ll tmp = (y + x) % 3;
            ll dest_c;
            switch (tmp){
                case 0: dest_c = i; break;
                case 1: dest_c = j; break;
                case 2: dest_c = k; break;
            }
            if (c[y][x] != dest_c){cand += D[c[y][x]][dest_c];}
        }}

        if (cand < ans){ans = cand;}
    }}}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
