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
    ll A, B, Q; cin >> A >> B >> Q;
    vector<ll> s(A + 2), t(B + 2);
    // 左右端の処理が面倒なので-INF/INFを詰める
    rep(i, A){cin >> s.at(i + 1);} s.at(0) = -INF;  s.at(A + 1) = INF;
    rep(i, B){cin >> t.at(i + 1);} t.at(0) = -INF;  t.at(B + 1) = INF;

    vector<ll> vec;
    rep(i, Q){
        ll x; cin >> x;
        auto iter_s = upper_bound(s.begin(), s.end(), x);
        ll right_ind_s = distance(s.begin(), iter_s);
        ll left_ind_s = right_ind_s - 1;

        auto iter_t = upper_bound(t.begin(), t.end(), x);
        ll right_ind_t = distance(t.begin(), iter_t);
        ll left_ind_t = right_ind_t - 1;

        // ll ans = INF;
        vector<ll> answers;

        // 4パターン網羅しなきゃいけない
        answers.push_back(x - min(s.at(left_ind_s), t.at(left_ind_t))); // (左，左)
        answers.push_back(max(s.at(right_ind_s), t.at(right_ind_t)) - x); // (右，右)
        answers.push_back(min(
            2 * (x - s.at(left_ind_s)) + (t.at(right_ind_t) - x),
            (x - s.at(left_ind_s)) + 2 * (t.at(right_ind_t) - x)
        )); // (左，右)
        answers.push_back(min(
            2 * (x - t.at(left_ind_t)) + (s.at(right_ind_s) - x),
            (x - t.at(left_ind_t)) + 2 * (s.at(right_ind_s) - x)
        )); // (右，左)
        vec.push_back(*min_element(answers.begin(), answers.end()));
    }
    for (auto v: vec){cout << v << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
