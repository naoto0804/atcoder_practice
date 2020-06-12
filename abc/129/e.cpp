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
    // dp1[k]: 上からk桁目まで確定させ，その時点でA+BがL以下だとわかっているもの
    // dp2[k]: 上からk桁目まで確定させ，その時点でA+BがL以下だとわかっていないもの
    string L; cin >> L;
    ll N = L.size();
    ll dp1[N + 1], dp2[N + 1];
    dp1[0] = 0; dp2[0] = 1;
    rep(i, L.size()){
        if (L[i] == '1'){
            dp2[i + 1] = 2 * dp2[i]; // (0, 1) or (1, 0)
            dp1[i + 1] = 3 * dp1[i] + dp2[i]; // (0, 0) の場合だけdp2から遷移してくる, 確定している場合は繰り上がりを出さなければ何でも良い
        } else {
            dp2[i + 1] = dp2[i]; // (0, 0)しか選択肢が無い，(繰り上がりはNGなので未確定のものは増えない)
            dp1[i + 1] = 3 * dp1[i];
        }
        dp1[i + 1] %= MOD; dp2[i + 1] %= MOD;
    }
    // rep(i, N + 1){cout << dp1[i] << " ";} cout << endl;
    // rep(i, N + 1){cout << dp2[i] << " ";} cout << endl;

    cout << (dp1[N] + dp2[N]) % MOD << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
