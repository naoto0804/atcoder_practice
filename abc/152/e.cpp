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

void Main() {
    // 最大公約数がoverflowするので，素因数分解
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    vector<map<ll, ll>> x;
    rep(i, N){
        cin >> A.at(i);
        x.push_back(prime_factorize(A.at(i)));
    }
    map<ll, ll> tmp = x.at(0);
    rep(i, N - 1){
        for (auto a: x.at(i + 1)){
            if (tmp.find(a.first) != tmp.end()){
                tmp[a.first] = max(a.second, tmp[a.first]);
            } else {
                tmp[a.first] = a.second;
            }
        }
    }

    ll ans = 0;
    rep(i, N){
        map<ll, ll> b_cnt(tmp);
        for (auto a: x.at(i)){b_cnt[a.first] -= a.second;}
        ll b = 1;
        for (auto a: b_cnt){
            rep(i, a.second){b = b * a.first % MOD;}
        }
        ans = (ans + b) % MOD;
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
