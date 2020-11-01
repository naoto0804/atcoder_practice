// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

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
    ll N, M; cin >> N >> M;
    vector<ll> H(N), W(M), left_acc_sum((N - 1) / 2, INF), right_acc_sum((N - 1) / 2, INF);
    rep(i, N){cin >> H.at(i);}
    rep(i, M){cin >> W.at(i);}
    sort(H.begin(), H.end());
    sort(W.begin(), W.end());

    ll K = (N - 1) / 2;
    // 左から何組使うか
    rep(i, K){
        ll tmp = H.at(2 * i + 1) - H.at(2 * i);
        if (i > 0){tmp += left_acc_sum.at(i - 1);}
        left_acc_sum.at(i) = tmp;
    }
    // 右から何組使うか
    rep(i, K){
        ll tmp = H.at(N - 1 - 2 * i) - H.at(N - 2 - 2 * i);
        if (i > 0){tmp += right_acc_sum.at(i - 1);}
        right_acc_sum.at(i) = tmp;
    }
    ll ans = INF;
    for (auto w: W){
        auto it = lower_bound(H.begin(), H.end(), w);
        ll ind = it - H.begin();
        ll tmp, left_cnt, right_cnt;
        if (ind % 2 == 0){ // 右側のやつと組む
            tmp = H.at(ind) - w;
            left_cnt = ind / 2;
        } else { // 左側のやつと組む
            tmp = w - H.at(ind - 1);
            left_cnt = max(0, (int)(ind - 1) / 2);
        }
        right_cnt = K - left_cnt;
        if (left_cnt > 0){tmp += left_acc_sum.at(left_cnt - 1);}
        if (right_cnt > 0){tmp += right_acc_sum.at(right_cnt - 1);}
        // cout << w << " " << ind << " " << tmp << endl;
        if (tmp < ans){ans = tmp;}
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
