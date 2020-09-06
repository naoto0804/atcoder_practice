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
    ll any_cnt = 0;
    map<ll, ll> x; rep(i, 8){x[i] = 0;}
    rep(i, N){
        ll tmp; cin >> tmp;
        if (1 <= tmp && tmp <= 399){x[0] += 1;}
        else if (400 <= tmp && tmp <= 799){x[1] += 1;}
        else if (800 <= tmp && tmp <= 1199){x[2] += 1;}
        else if (1200 <= tmp && tmp <= 1599){x[3] += 1;}
        else if (1600 <= tmp && tmp <= 1999){x[4] += 1;}
        else if (2000 <= tmp && tmp <= 2399){x[5] += 1;}
        else if (2400 <= tmp && tmp <= 2799){x[6] += 1;}
        else if (2800 <= tmp && tmp <= 3199){x[7] += 1;}
        else {any_cnt += 1;}
    }
    ll ans = 0;
    rep(i, 8){
        if (x[i] > 0){ans += 1;}
    }
    cout << ans << " " << min(ans + any_cnt, (ll)8) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
