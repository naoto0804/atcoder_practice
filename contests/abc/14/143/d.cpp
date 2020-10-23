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
    int N;
    cin >> N;
    vector<int> L;
    ll ans = 0;
    rep(i, N){int a; cin >> a; L.push_back(a);}
    sort(L.begin(), L.end());
    for (ll i=0; i<(ll)(N); i++){
        for (ll j=i+1; j<(ll)(N); j++){
            // 大きい方から2つpick-upしたので(x1, x2)，x3の満たす条件は abs(x1 - x2) < x3 < x1, これを二部探索
            int d = abs(L.at(i) - L.at(j));
            auto it = upper_bound(L.begin(), L.end(), d);
            int dd = distance(L.begin(), it); // abs(x1 - x2)より大きい値を挿入できる最初の場所を返す
            if(i > dd) ans += i - dd;
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
