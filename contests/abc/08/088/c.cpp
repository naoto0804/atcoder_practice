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
    ll c[3][3]; rep(i, 3){rep(j, 3){cin >> c[i][j];}}
    // aにxを加算してbからxを減産してもok -> a1=0を仮定して話をすすめる
    ll a[3], b[3]; a[0] = 0;
    rep(j, 3){b[j] = c[0][j];}

    bool flag = true;
    rep2(i, 1, 3){
        ll tmp = c[i][0] - b[0];
        if (tmp != (c[i][1] - b[1])){flag = false; break;}
        if (tmp != (c[i][2] - b[2])){flag = false; break;}
    }
    string ans = flag ? "Yes" : "No";
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
