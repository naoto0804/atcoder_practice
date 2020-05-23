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

// 素因数分解
map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}

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
    if (N >= 3){
        vector<ll> A(N); rep(i, N){cin >> A.at(i);}
        // N^{2}を避けるため，累積最大公約数という概念を導入
        // Li: 0, 1, ..., i-1 の最大公約数
        // Ri: i, ... N - 1 の最大公約数
        vector<ll> L(N + 1), R(N + 1); L.at(0) = 0; R.at(N) = 0;
        rep(i, N){L.at(i + 1) = __gcd(L.at(i), A.at(i));}
        rrep(i, N, 1){R.at(i - 1) = __gcd(R.at(i), A.at(i - 1));}

        ll ans = 1;
        rep(i, N){
            ll tmp = __gcd(L.at(i), R.at(i + 1));
            if (ans < tmp){ans = tmp;}
        }
        cout << ans << endl;
    } else {
        vector<ll> A(N);
        rep(i, N){cin >> A.at(i);}
        cout << *max_element(A.begin(), A.end()) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
