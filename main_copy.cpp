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
    int K;
    K = 3;
    // cin >> K;
    // cout << sum << " " << A.at(M - 1) << " " << (sum / (4 * M)) << endl;
    ll ans;
    int N = 10;
    ll dp[N][10];
    ll sum_dp[N][10];
    rep(i, N){
        if (i == 0){
            rep(j, 10){dp[0][j] = 1;}
        } else if (i == 1){
            rep(j, 10){
                dp[1][j] = (j == 9 || j == 0) ? 2 : 3;
            }
        } else {
            rep(j, 10){
                if (j == 0){
                    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
                } else if (j == 9){
                    dp[i][9] = dp[i - 1][8] + dp[i - 1][9];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
                }
            }
        }
    }
    // rep(i, 10){rep(j, N){cout << i << " " << j << " " << dp[i][j] << endl;}}
    ll tmp = 0;
    rep(i, N){rep(j, 10){
        if (j == 0){continue;}
        tmp += sum_dp[i][j];
        sum_dp[i][j] = tmp;
        cout << i << " " << j << " " << tmp << endl;
    }}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
