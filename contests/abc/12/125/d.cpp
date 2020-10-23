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
    vector<ll> A(N);
    rep(i, N){cin >> A.at(i);}
    ll dp[N+1][2];
    // i番目，jはこの桁(と前の桁)で反転を入れるかの有無
    dp[0][0] = 0;
    dp[0][1] = -INF; // dp[0][1]は絶対に使われない
    rep(i, N){
        dp[i+1][0] = max(dp[i][0] + A.at(i), dp[i][1] - A.at(i));
        dp[i+1][1] = max(dp[i][0] - A.at(i), dp[i][1] + A.at(i));
    }
    cout << dp[N][0] << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
