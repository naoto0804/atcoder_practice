// ctrl+shift+b
#include <bits/stdc++.h>

using namespace std;

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

// map<ll, ll> cache;

// ll pow(ll x, ll y, ll mod) {
//     if (cache.find(y) != cache.end()){
//         cout << "Cache " << y << " " << cache[y] << endl;
//         return cache[y];
//     } else if (y == 0) {
//             return 1;
//     } else {
//         ll hoge;
//         cout << "L39 " << y << endl;
//         if (y % 2 == 0) {
//             hoge = pow(x * x % mod, y / 2, mod) % mod;
//         } else {
//             hoge = x * pow(x, y - 1, mod) % mod;
//         }
//         cout << "L45 " << y << " " << hoge << endl;
//         cache[y] = hoge;
//         return hoge;
//     }
// }

void Main() {
    ll H, W; cin >> H >> W;
    ll arr[H][W], acc_sum[H][W]; rep(i, H){rep(j, W){arr[i][j] = 0; acc_sum[i][j] = 0;}}
    ll cnt = 0;
    rep(i, H){
        string S; cin >> S;
        rep(j, W){
            if(S[j] == '.'){
                arr[i][j] = 1;
                cnt++;
            }
        }
    }

    map<ll, ll> cache;
    rep(i, cnt + 1){
        if (i == 0){
            cache[i] = 1;
        }else{
            cache[i] = cache[i - 1] * 2 % MOD;
        }
    }

    rep(i, H){ll tmp = 0; rep(j, W){if (arr[i][j] == 1){acc_sum[i][j] += tmp; tmp++;}else{tmp=0;}}} // left to right
    rep(i, H){ll tmp = 0; rrep(j, W - 1, 0){if (arr[i][j] == 1){acc_sum[i][j] += tmp; tmp++;}else{tmp=0;}}} // right to left
    rep(j, W){ll tmp = 0; rep(i, H){if (arr[i][j] == 1){acc_sum[i][j] += tmp; tmp++;}else{tmp=0;}}} // top to bottom
    rep(j, W){ll tmp = 0; rrep(i, H - 1, 0){if (arr[i][j] == 1){acc_sum[i][j] += tmp; tmp++;}else{tmp=0;}}} // bottom to top

    ll ans = 0;
    // ll base = pow(2, cnt, MOD);
    ll base = cache[cnt];
    rep(i, H){
        rep(j, W){
            if (arr[i][j] == 0){continue;}
            // ll tmp = base - pow(2, cnt - (acc_sum[i][j] + 1), MOD);
            ll tmp = base - cache[cnt - (acc_sum[i][j] + 1)];
            if (tmp < 0){tmp += MOD;}
            ans = (ans + tmp) % MOD;
        }
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
