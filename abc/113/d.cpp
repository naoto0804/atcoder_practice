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
    ll H, W, K; cin >> H >> W >> K;

    ll HMAX = 7;
    vector<ll> vec(HMAX); // 間の個数に対して，何通りの配置があるか考える，メモ化しておく
    vec.at(0) = 0;
    rep2(w, 1, HMAX){
        ll cnt = 0;
        for (int bit = 0; bit < (1<<w); ++bit) {
            vector<int> S;
            for (int i = 0; i < HMAX; ++i) {
                if (bit & (1<<i)) {S.push_back(i);}
            }
            ll prev = -2;
            bool flag = true;
            for (auto s: S){
                // 連続してつなぐのはNG
                if (s == prev + 1){flag = false; break;}
                prev = s;
            }
            if (flag){cnt++;}
        }
        vec.at(w) = cnt;
    }

    // dp[i][j]: i段目のj個目の場所にたどり着く場合の数
    ll dp[H + 1][W]; rep(i, H + 1){rep(j, W){dp[i][j] = 0;}}
    dp[0][0] = 1;

    rep(i, H){rep(j, W){
        ll tmp, l, r;
        if (j - 1 >= 0){ // 左から流入
            tmp = 1;
            l = ((j - 1) - 0) - 1; if (l > 0){tmp *= vec.at(l);}
            r = ((W - 1) - j) - 1; if (r > 0){tmp *= vec.at(r);}
            dp[i + 1][j] += tmp * dp[i][j - 1] % MOD;
            dp[i + 1][j] %= MOD;
        }
        if (j + 1 <= W - 1){ // 右から流入
            tmp = 1;
            l = (j - 0) - 1; if (l > 0){tmp *= vec.at(l);}
            r = ((W - 1) - (j + 1)) - 1; if (r > 0){tmp *= vec.at(r);}
            dp[i + 1][j] += tmp * dp[i][j + 1] % MOD;
            dp[i + 1][j] %= MOD;
        }

        // 同じ所から流入
        tmp = 1;
        l = (j - 0) - 1; if (l > 0){tmp *= vec.at(l);}
        r = ((W - 1) - j) - 1; if (r > 0){tmp *= vec.at(r);}
        dp[i + 1][j] += tmp * dp[i][j] % MOD;
        dp[i + 1][j] %= MOD;
    }}

    // rep(j, W){cout << dp[H][j] << " ";}
    // cout << endl;
    cout << dp[H][K - 1] << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
