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

ll f(ll N, ll X, vector<ll> a, vector<ll> p){
    if (N == 0){if (X <= 0){return 0;} else {return 1;}}
    else if (X <= (1 + a.at(N-1))){
        return f(N-1, X-1, a, p);
    } else {
        return p.at(N-1) + 1 + f(N-1, X - 2 - a.at(N-1), a, p);
    }
}

void Main() {
    ll N, X; cin >> N >> X;

    // 厚さ a_{i}: a_{0} = 1, a_{i} = 2 * a_{i-1} + 3
    // パティ p_{i}: p_{0} = 1, p_{i} = 2 * p_{i-1} + 1
    // レベルNバーガーの下層からX層に含まれるパティの枚数 f(N,X)を漸化式を立てて下って求める
    vector<ll> a(N+1), p(N+1);
    a.at(0) = 1; p.at(0) = 1;
    rep(i, N){a.at(i+1) = 2 * a.at(i) + 3; p.at(i+1) = 2 * p.at(i) + 1;}
    cout << f(N, X, a, p) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
