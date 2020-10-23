// ctrl+shift+b
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
    // 二次元いもす, 二次元累積和
    ll h, w; cin >> h >> w;
    ll x[h + 1][w + 1]; rep(i, h + 1){rep(j, w + 1){x[i][j] = 0;}} // 累積和取るようにpaddingを入れる
    rep(i, h){
        rep(j, w){
            ll tmp;
            cin >> tmp;
            if ((i + j) % 2 == 0){
                x[i + 1][j + 1] = tmp;
            } else {
                // Wは反転させて入れる
                x[i + 1][j + 1] = -tmp;
            }
        }
    }

    // arrayをとりあえず可視化
    // rep(i, h + 1){
    //     rep(j, w + 1){cout << x[i][j] << " ";}
    //     cout << endl;
    // }
    // cout << endl;


    // 二次元累積和
    ll acc_x[h + 1][w + 1]; rep(i, h + 1){rep(j, w + 1){acc_x[i][j] = 0;}}
    // x方向
    rep(i, h + 1){
        rep(j, w + 1){
            if (j != 0){
                acc_x[i][j] = x[i][j] + acc_x[i][j - 1];
            }
        }
    }
    // y方向
    rep(j, w + 1){
        rep(i, h + 1){
            if (i != 0){
                acc_x[i][j] += acc_x[i - 1][j];
            }
        }
    }

    ll area_max = 0;
    rep(y1, h + 1){rep(y2, h + 1){
        if (y1 > y2){continue;}
        rep(x1, w + 1){rep(x2, w + 1){
            if (x1 > x2){continue;}
            // (x1, x2] かつ (y1, y2] の領域の累積和が欲しい，長方形の足し引きで表現するおなじみのやつ
            ll tmp = acc_x[y2][x2] - acc_x[y2][x1] - acc_x[y1][x2] + acc_x[y1][x1];
            if (tmp == 0){
                ll area = (y2 - y1) * (x2 - x1);
                if (area_max < area){area_max = area;}
            }
        }}
    }}
    cout << area_max << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
