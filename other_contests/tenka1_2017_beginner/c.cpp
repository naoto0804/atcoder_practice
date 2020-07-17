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
    // h, n, w 全部ループすると足りないので，(h, n, N) を与えたときに条件を満たすwが出るか調べる
    ll N; cin >> N;
    ll MAX = 3500;
    bool flag = false;
    rep2(h, 1, MAX + 1){
        rep2(n, h, MAX + 1){
            ll numerator = h * n * N; // 分子
            ll denominator = 4 * n * h - N * n - N * h; // 分母
            if (denominator != 0 && numerator % denominator == 0){
                ll w = numerator / denominator;
                if (w > 0){
                    cout << h << " " << n << " " << w; flag = true; break;
                }
            }
        }
        if (flag){break;}
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
