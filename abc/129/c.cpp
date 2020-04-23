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
    set<ll> a;
    rep(i, M){int tmp; cin >> tmp; a.insert(tmp);}
    vector<ll> dp(N+1, 0);
    dp.at(0) = 1;
    rep2(i, 1, N+1){
        // 毎回MOD取らないと途轍もない大きさになるので注意
        if ((i - 2 >= 0) && (a.find(i-2) == a.end())){dp.at(i) += dp.at(i-2); dp.at(i) = dp.at(i) % MOD;}
        if ((i - 1 >= 0) && (a.find(i-1) == a.end())){dp.at(i) += dp.at(i-1); dp.at(i) = dp.at(i) % MOD;}
    }
    cout << dp.at(N) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
