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
    ll A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    // 中途半端なケースが最大になることはほぼないはず
    // (i) 全文単品
    // (ii) 全部AB
    // (iii) あるところまでAB, のちに単品
    vector<ll> ans(3);
    ans.at(0) = X * A + Y * B;
    ans.at(1) = 2 * max(X, Y) * C;
    ans.at(2) = 2 * min(X, Y) * C;
    if (X > Y){
        ans.at(2) += A * (X - Y);
    } else {
        ans.at(2) += B * (Y - X);
    }
    cout << *min_element(ans.begin(), ans.end()) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
