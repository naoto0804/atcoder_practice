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
    ll N, A; cin >> N >> A;
    vector<ll> x(N); rep(i, N){cin >> x.at(i);}
    // dp[j][k][s] ~x_{j-1}の中からk枚選んで合計をsにするような選び方の総数
    ll X = max(A, *max_element(x.begin(), x.end()));
    ll dp[N + 1][N + 1][N * X + 1];
    rep(j, N + 1){rep(k, N + 1){rep(s, N * X + 1){dp[j][k][s] = 0;}}}
    dp[0][0][0] = 1;
    rep2(j, 1, N + 1){rep(k, N + 1){
        rep(s, N * X + 1){
            dp[j][k][s] += dp[j - 1][k][s];
            if (s - x.at(j - 1) >= 0){dp[j][k][s] += dp[j - 1][k - 1][s - x.at(j - 1)];}
        }
    }}
    ll ans = 0;
    rep2(k, 1, N + 1){ans += dp[N][k][k * A];}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
