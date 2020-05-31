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
    string s, t; cin >> s >> t;
    // 条件は
    // (i) tの各文字がsに存在すること (個数は問わない)

    map<ll, vector<ll>> x; // 各アルファベットがindとしていくつのところで出てくるか
    rep(i, s.size()){x[s[i] - 'a'].push_back(i);}
    rep(i, t.size()){if (x[t[i] - 'a'].size() == 0){cout << -1 << endl; exit(0);}}

    ll n_rep = 0, s_ind = -1;
    ll t_ind = 0;

    while(t_ind < t.size()){
        vector<ll> inds = x[t[t_ind] - 'a']; // t[t_ind]の文字が出てくる場所の配列
        // ソート済みなので，s_indより大きい(同じは含まない)座標値が見つかるかを二分探索
        if (*max_element(inds.begin(), inds.end()) <= s_ind){ // 文字が見つからなかったら最初に戻ってもう一回探す
            n_rep++; s_ind = -1;
        } else { // 文字が見つかったら次の文字に移行
            auto pos = upper_bound(inds.begin(), inds.end(), s_ind);
            s_ind = inds[distance(inds.begin(), pos)];
            t_ind++;
        }
    }
    cout << n_rep * s.size() + s_ind + 1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
