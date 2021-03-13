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

vector<ll> get_sums(vector<ll> x){
    vector<ll> sums;
    for (ll bit = 0; bit < (1<<x.size()); ++bit) {
        vector<ll> S;
        for (ll i = 0; i < 10; ++i) {
            if (bit & (1<<i)) {
                S.push_back(i);
            }
        }
        ll tmp = 0;
        for (auto s: S){tmp += x.at(s);}
        sums.push_back(tmp);
    }
    sort(sums.begin(), sums.end());
    return sums;
}

void Main() {
    ll N, T; cin >> N >> T;
    vector<ll> A; rep(i, N){ll a; cin >> a; A.push_back(a);}

    // 半分全列挙, 2^{N}の解法でもNが20程度までなら間に合うので問題を分割
    ll M = (ll) (N / 2);
    vector<ll> first_half = vector<ll>(A.begin(), A.begin() + M);
    vector<ll> second_half = vector<ll>(A.begin() + M, A.end());

    vector<ll> sums_first_half = get_sums(first_half);
    vector<ll> sums_second_half = get_sums(second_half);
    ll ans = 0;
    for (auto s: sums_second_half){
        if (s > T){continue;}
        auto it = lower_bound(sums_first_half.begin(), sums_first_half.end(), T - s);
        ll ind = it - sums_first_half.begin();
        if (ind >= sums_first_half.size()){ind = sums_first_half.size() - 1;}
        ll tmp = s + sums_first_half.at(ind);
        if (tmp > ans && tmp <= T){ans = tmp;}
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
