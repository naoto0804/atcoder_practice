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
    // 下一桁が最も小さいものを最後に選べば後の順番はどうでもいい
    ll N = 5;
    vector<ll> x(N), y(N);
    vector<int> indices(N);
    rep(i, N){cin >> x.at(i);}
    rep(i, N){y.at(i) = (x.at(i) % 10 == 0) ? 10 : (x.at(i) % 10);}
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&y](ll i1, ll i2) {
        return y[i1] < y[i2]; // これは昇順
    });
    ll ans = 0;
    rep(i, N){
        if (i == indices.at(0)){
            ans += x.at(i);
        } else {
            ans += (ll) ceil((double) x.at(i) / 10) * 10;
        }
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
