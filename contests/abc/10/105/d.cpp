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
    ll N, M; cin >> N >> M;
    vector<ll> A(N), B(N + 1);
    rep(i, N){cin >> A.at(i);}
    B.at(0) = 0; rep(i, N){B.at(i + 1) = (B.at(i) + A.at(i));}
    map<ll, ll> x;
    rep(i, N + 1){
        ll remainder = B.at(i) % M;
        if (x.find(remainder) == x.end()){x[remainder] = 1;}else{x[remainder]++;}
    }
    ll ans = 0;
    for (auto a: x){
        ans +=  a.second * (a.second - 1) / 2;
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
