// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll> >;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[3] = {-1, 0, -1};
const int dy[3] = {0, -1, -1};
// const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll mod_inverse(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

vector<vector<ll>> matmul(vector<vector<ll>> mat1, vector<vector<ll>> mat2, ll N){
    vector<vector<ll>> x;
    rep(i, N){
        rep(j, N){
            x.at(i).at(j) = mat1.at(i).at(j) * mat2.at(j).at(i);
        }
    }
    return x;
}

void Main() {
    // ll N; cin >> N;
    ll N = 2;
    vector<vector<ll>> x;
    x.at(0).at(0) = 0.5;
    x.at(0).at(1) = 0.3;
    x.at(1).at(0) = 0.7;
    x.at(1).at(1) = 0.1;

    vector<vector<ll>> y;
    y.at(0).at(0) = 1.0;
    y.at(0).at(1) = 0.0;
    y.at(1).at(0) = 0.0;
    y.at(1).at(1) = 1.0;

    vector<vector<ll>> ans = matmul(x, y, N);
    rep(i, N){
        rep(j, N){cout << ans.at(i).at(j) << " ";}
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
