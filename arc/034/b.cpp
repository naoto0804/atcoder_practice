// ctrl+shift+b
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

ll get_f_n(ll n){
    ll tmp = 0;
    while (n > 0){
        tmp += n % 10;
        n = n / 10;
    }
    return tmp;
}

void Main() {
    ll N; cin >> N;
    // nがM桁の時，0 <= f(n) <= 9 * M なので探索範囲はかなり狭い
    // rep2(i, N - )
    ll M = 9 * (ll) ceil(log10(N + 1));
    vector<ll> ans;
    rep2(n, N - M, N + 1){
        ll f_n = get_f_n(n);
        if (n + f_n == N){
            ans.push_back(n);
        }
    }
    cout << ans.size() << endl;
    for (auto a: ans){cout << a << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
