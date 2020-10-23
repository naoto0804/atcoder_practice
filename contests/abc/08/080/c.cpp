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
    bool F[N][5][2];
    rep(i, N){
        rep(j, 5){
            ll a, b; cin >> a >> b;
            F[i][j][0] = (a == 1) ? true : false;
            F[i][j][1] = (b == 1) ? true : false;
        }
    }
    ll P[N][11];
    rep(i, N){rep(j, 11){cin >> P[i][j];}}

    // bit全探索
    ll ans = -INF;
    for (int bit = 0; bit < (1<<10); ++bit) { // 1を左に2回シフトすると100
        vector<int> S;
        for (int i = 0; i < 10; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        if (S.size() == 0){continue;}

        ll tmp = 0;
        rep(i, N){
            ll cnt = 0;
            for (auto s: S){
                if (F[i][s % 5][s / 5]){cnt += 1;}
            }
            tmp += P[i][cnt];
        }
        if (tmp > ans){ans = tmp;}
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
