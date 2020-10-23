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
// const ll MOD = 1000000007;
const ll MOD = 998244353;

const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    ll N, S; cin >> N >> S;
    vector<ll> A(N);
    rep(i, N){cin >> A.at(i);}

    // UはTの部分集合
    // U に関してはax1 + ax2 + ... = S
    // この時，iに関して
    // (i) UにもTにも入れる (ii) Tだけに入れる (iii) どちらにも入れない
    // dp[i][j]: i番目までの選択をして，1つめの選択肢を選んだkに対するa_{k}の和がjとなる場合の数
    ll dp[N + 1][S + 1];
    rep(i, N + 1){rep(j, S + 1){dp[i][j] = 0;}}
    dp[0][0] = 1; // 開始状態
    rep(i, N){
        rep(j, S + 1){
            dp[i + 1][j] += 2 * dp[i][j]; // (ii)と(iii)ではスコアは変わらないのでこっち
            dp[i + 1][j] %= MOD;
            if (j + A.at(i) <= S){
                dp[i + 1][j + A.at(i)] += dp[i][j];
                dp[i + 1][j + A.at(i)] %= MOD;
            }
        }
    }
    cout << dp[N][S] << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
