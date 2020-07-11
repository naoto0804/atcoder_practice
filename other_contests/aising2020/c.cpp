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
    ll N; cin >> N;
    ll maxn = sqrt(N) + 1;
    map<ll, ll> res;
    rep2(x, 1, maxn){rep2(y, 1, maxn){rep2(z, 1, maxn){
        ll n = x * x + y * y + z * z + x * y + y * z + z * x;
        if (res.find(n) != res.end()){
            res[n]++;
        } else {
            res[n] = 1;
        }
    }}}
    rep2(i, 1, N + 1){
        if (res.find(i) != res.end()){
            cout << res[i] << endl;
        } else {
            cout << 0 << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
