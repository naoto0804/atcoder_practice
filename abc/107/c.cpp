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
    ll N, K; cin >> N >> K;
    vector<ll> x(N); rep(i, N){cin >> x.at(i);}

    ll cost = INF;
    rep(l, N - K + 1){
        ll ans;
        ll ansl = abs(x.at(l)) + abs(x.at(l+K-1)-x.at(l));
        ll ansr = abs(x.at(l+K-1)) + abs(x.at(l+K-1)-x.at(l));
        ans = (ansl > ansr) ? ansr : ansl;
        if (ans < cost){cost = ans;}
    }
    cout << cost << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
