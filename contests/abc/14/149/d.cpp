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


ll best_move(vector<int> group, int scores[]){
    // r -> 0, s -> 1, p -> 2
    // group: 理想的には何を出すべきかの配列
    // dp[i][j]: i個目にjを出すときの最大スコア
    int N = group.size();
    ll dp[N+1][3];
    rep(i, 3){dp[0][i] = 0;}
    rep(i, group.size()){
        // 前に選んだ要素は使えない
        if (group.at(i) == 0){
            dp[i + 1][0] = scores[0] + max(dp[i][1], dp[i][2]);
            dp[i + 1][1] = max(dp[i][0], dp[i][2]);
            dp[i + 1][2] = max(dp[i][0], dp[i][1]);
        } else if (group.at(i) == 1){
            dp[i + 1][0] = max(dp[i][1], dp[i][2]);
            dp[i + 1][1] = scores[1] + max(dp[i][0], dp[i][2]);
            dp[i + 1][2] = max(dp[i][0], dp[i][1]);
        } else {
            dp[i + 1][0] = max(dp[i][1], dp[i][2]);
            dp[i + 1][1] = max(dp[i][0], dp[i][2]);
            dp[i + 1][2] = scores[2] + max(dp[i][0], dp[i][1]);
        }
    }
    return max(dp[N][0], max(dp[N][1], dp[N][2]));
}

void Main() {
    int N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    // modKで分ければDPに落とし込める
    int scores[] = {R, S, P};
    vector<vector<int>> groups(K);
    rep(i, T.size()){
        int tmp = INF;
        if (T[i] == 'r'){tmp = 2;}
        if (T[i] == 's'){tmp = 0;}
        if (T[i] == 'p'){tmp = 1;}
        groups.at(i % K).push_back(tmp);
    }
    ll ans = 0;
    for (auto g : groups){ans += best_move(g, scores);}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
