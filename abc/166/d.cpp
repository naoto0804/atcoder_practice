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
    // 因数分解するまでも無かった.. 解はbについて単調減少なのがキモ，なのでb = a - 1の時を考えて範囲評価
    // n^{5}-(n-1)^{5}が初めて10^9を超えるときを考えると -118 <= A <= 119
    ll X; cin >> X;
    ll low = -1;
    ll high = 10000;
    vector<ll> div = divisor(X);
    bool flag = false;
    rep2(i, -120, 120){
        rep2(j, -120, 120){
            ll cand = pow(i, 5, INF) - pow(j, 5, INF);
            if (cand == X){cout << i << " " << j << endl; flag = true; break;}
        }
        if(flag){break;}
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
