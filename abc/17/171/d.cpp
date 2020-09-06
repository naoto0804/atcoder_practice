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
    ll N, Q; cin >> N;
    map<ll, ll> x;
    ll ans = 0;

    rep(i, N){
        ll a; cin >> a;
        if (x.find(a) != x.end()){
            x[a]++;
        } else {
            x[a] = 1;
        }
        ans += a;
    }

    vector<ll> y;
    cin >> Q;
    rep(i, Q){
        ll b, c;
        cin >> b >> c;
        if (x.find(b) != x.end()){
            ans -= b * x[b];
            ans += c * x[b];
            if (x.find(c) != x.end()){
                x[c] += x[b];
            } else {
                x[c] = x[b];
            }
            x[b] = 0;
        }
        y.push_back(ans);
    }
    for (auto a: y){cout << a << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
