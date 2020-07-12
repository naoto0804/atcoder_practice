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
    // ありえる組み合わせはたかだか1000通りなので，各場合についてSを左から見ていって3要素が出るかを探す
    ll N; cin >> N;
    string S; cin >> S;
    ll cnt = 0;
    rep(i, 10){rep(j, 10){rep(k, 10){
        vector<ll> inds = {i, j, k};
        ll cur_ind = 0;
        rep(n, N){
            if ((S[n] - '0') == inds[cur_ind]){cur_ind++;}
            if (cur_ind == 3){cnt++; break;}
        }
    }}}
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
