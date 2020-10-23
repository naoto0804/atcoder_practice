// ctrl+shift+b
#include <bits/stdc++.h>

using namespace std;

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
    ll N; cin >> N;
    // 座標変換 (x, y) -> (x + y, x - y)
    // |x1 - x2| + |y1 - y2| = max(|z1 - z2|, |w1 - w2|)
    vector<ll> a(N), b(N);
    rep(i, N){
        ll x, y; cin >> x >> y;
        a.at(i) = x + y;
        b.at(i) = x - y;
    }
    ll a_range = *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end());
    ll b_range = *max_element(b.begin(), b.end()) - *min_element(b.begin(), b.end());
    cout << max(a_range, b_range) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
