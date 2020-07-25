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
const ll MOD = 998244353;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

ll pow(ll x, ll y, ll mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return pow(x * x % mod, y / 2, mod) % mod;
    } else {
        return x * pow(x, y - 1, mod) % mod;
    }
}

void Main() {
    ll N; cin >> N;
    // vector<ll> D(N); rep(i, N){cin >> D.at(i);}
    map<ll, ll> x;
    rep(i, N){
        ll d; cin >> d;
        if (x.find(d) != x.end()){
            x[d]++;
        } else {
            x[d] = 1;
        }
    }
    if (x[0] != 1){
        cout << 0 << endl;
    } else {
        ll ans = 1;
        for (auto a: x){
            if (a.first == 0){continue;}
            if (x.find(a.first - 1) == x.end()){cout << 0 << endl; exit(0);}
            ans = ans * pow(x[a.first - 1], a.second, MOD) % MOD;
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
