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

ll find_maximum(ll a[], ll n) {
    int c, max;

    max = a[0];

    for (c = 1; c < n; c++) {
        if (a[c] > max) {
            max = a[c];
        }
    }

    return max;
}


void Main() {
    // 行が変わるときにリセットされるだけの動的計画法
    ll R, C, K; cin >> R >> C >> K;
    ll arr[R + 1][C + 1][4]; rep(i, R + 1){rep(j, C + 1){rep(k, 4){arr[i][j][k] = 0;}}}
    map<P, ll> x;
    rep(i, K){
        ll r, c, v; cin >> r >> c >> v;
        x[make_pair(r, c)] = v;
    }
    rep2(i, 1, R + 1){
        rep2(j, 1, C + 1){
            rep(k, 4){
                arr[i][j][k] = max(arr[i][j - 1][k], find_maximum(arr[i - 1][j], 4));
                if (k != 0){
                    P p = make_pair(i, j);
                    if (x.find(p) != x.end()){
                        ll v = x[p];
                        arr[i][j][k] = max(arr[i][j][k], max(find_maximum(arr[i - 1][j], 4), arr[i][j - 1][k - 1]) + v);
                    }
                }
            }
        }
    }
    ll ans = -INF;
    rep(i, 4){
        ll tmp = arr[R][C][i];
        if (tmp > ans){ans = tmp;}
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
