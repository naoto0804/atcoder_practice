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
    ll a[H][W];
    rep(i, H){
        string tmp; cin >> tmp;
        rep(j, W){
            if (tmp[j] == '#'){
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }

    ll cnt = 0;
    for (int rbit = 0; rbit < (1<<H); ++rbit) { // 1を左に2回シフトすると100
        vector<int> R;
        for (int i = 0; i < H; ++i) {
            if (rbit & (1<<i)) { // 列挙に i が含まれるか
                R.push_back(i);
            }
        }

        for (int cbit = 0; cbit < (1<<W); ++cbit) { // 1を左に2回シフトすると100
            vector<int> C;
            for (int i = 0; i < W; ++i) {
                if (cbit & (1<<i)) { // 列挙に i が含まれるか
                    C.push_back(i);
                }
            }

            // ひたすら探索
            ll tmp = 0;
            for (auto r: R){
                for (auto c: C){
                    tmp += a[r][c];
                }
            }
            if (tmp == K){cnt++;}
        }
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
