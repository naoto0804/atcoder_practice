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

vector<pair<char, ll>> RLE(const string &S) {
    ll cnt = 0;
    vector<pair<char, ll>> res;
    for (ll i = 0; i < (ll) S.size(); i++) {
        cnt++;
        if (i == (ll) S.size() - 1) {
            res.emplace_back(S[i], cnt);
            break;
        }
        if (S[i] != S[i + 1]) {
            res.emplace_back(S[i], cnt);
            cnt = 0;
        }
    }
    return res;
}

void Main() {
    string S;
    cin >> S;
    ll N = S.size();
    vector<pair<char, ll>> res = RLE(S);

    // R...RL...L のブロックごとに分割して考える
    ll cnt = 0;
    ll start_ind = 0;
    ll ans[N]; rep(i, N){ans[i] = 0;}
    while (true){
        if (cnt >= res.size()){break;}
        if (res[cnt].first == 'L'){
            cnt += 1;
            start_ind += res[cnt].second;
        } else {
            ll r_cnt = res[cnt].second;
            ll l_cnt = res[cnt + 1].second;
            ll tmp = r_cnt / 2 + (l_cnt + 1) / 2;
            ans[start_ind + r_cnt] = tmp;
            ans[start_ind + r_cnt - 1] = r_cnt + l_cnt - tmp;
            cnt += 2;
            start_ind += (r_cnt + l_cnt);
        }
    }
    rep(i, N){cout << ans[i] << " ";}
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
