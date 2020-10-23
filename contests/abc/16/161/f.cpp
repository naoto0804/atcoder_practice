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

// 約数列挙
vector<ll> divisor(ll N) {
    vector<ll> res;
    for (ll i = 1L; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            ll j = N / i;
            if (j != i)  {
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void Main() {
    ll N;
    cin >> N;
    ll ans = divisor(N - 1).size() - 1;
    vector<ll> divisor_n = divisor(N);
    for (auto v : divisor_n){
        ll tmp = N;
        if (v == 1){continue;}
        while (tmp % v == 0){tmp = tmp / v;}
        if (tmp % v == 1){ans += 1;}
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
