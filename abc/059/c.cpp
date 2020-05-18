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
    vector<ll> a(N); rep(i, N){cin >> a.at(i);}

    // 最初を負にする場合と正にする場合で少しだけ違う
    ll ans = INF;
    rep(i, 2){
        ll tmp_ans = 0, tmp = 0;
        rep(j, N){
            if ((j % 2 == 0) ^ (i == 0)){ // 累積和を正にしたい
                tmp += a.at(j);
                if (tmp <= 0){
                    tmp_ans += (1 - tmp);
                    tmp = 1;
                }
            } else {
                tmp += a.at(j);
                if (tmp >= 0){
                    tmp_ans += (tmp - (-1));
                    tmp = -1;
                }
            }
        }
        if (tmp_ans < ans){ans = tmp_ans;}
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
