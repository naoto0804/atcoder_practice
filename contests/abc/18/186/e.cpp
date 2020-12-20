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

void Main() {
    ll T; cin >> T;
    rep(i, T){
        ll N, S, K; cin >> N >> S >> K;
        // S + xK = 0 (modN) を見つければ良い
        // -> Kx = (N - S) (modN)
        // Ax = B (modM) の解き方は
        // (i) d = gcd(A, B, M)としてA,B,Mをそれぞれdで割る
        // (ii) gcd(A, M) != 1　の時解無し
        // (iii) gcd(A, M) == 1 の時modMにおけるAの逆元A^{-1}についてx=A^{-1}B
        ll A = K, B = N - S, M = N;
        ll d = gcd(gcd(A, B), M);
        A = A / d; B = B / d; M = M / d;
        if (gcd(A, M) != 1){
            cout << -1 << endl;
        } else {
            cout << mod_inverse(A, M) * B % M << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
