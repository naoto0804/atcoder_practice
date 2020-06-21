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
    ll MAX = 30;
    ll bin[N][MAX];
    ll ans[N][MAX];
    rep(i, N){
        ll a;
        cin >> a;
        rrep(j, MAX - 1, 0){
            bin[i][j] = a % 2;
            a = a / 2;
        }
    }
    rep(j, MAX){
        ll tmp = 0;
        rep(i, N){tmp += bin[i][j];}
        if (tmp % 2 == 0){
            rep(i, N){ans[i][j] = bin[i][j];}
        } else {
            rep(i, N){ans[i][j] = (bin[i][j] == 0) ? 1 : 0;}
        }
    }

    rep(i, N){
        ll tmp = 0;
        rep(j, MAX){
            tmp = tmp * 2 + ans[i][j];
        }
        cout << tmp << " ";
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
