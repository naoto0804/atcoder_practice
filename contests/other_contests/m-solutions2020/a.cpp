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
    ll X; cin >> X;
    ll ans;
    if (400 <= X && X <= 599){ans = 8;}
    else if (600 <= X && X <= 799){ans = 7;}
    else if (800 <= X && X <= 999){ans = 6;}
    else if (1000 <= X && X <= 1199){ans = 5;}
    else if (1200 <= X && X <= 1399){ans = 4;}
    else if (1400 <= X && X <= 1599){ans = 3;}
    else if (1600 <= X && X <= 1799){ans = 2;}
    else if (1800 <= X && X <= 1999){ans = 1;}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
