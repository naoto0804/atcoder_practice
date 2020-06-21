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
    ll N, x; cin >> N >> x;
    ll cnt = 0;
    vector<ll> a(N);
    rep(i, N){cin >> a.at(i);}
    rep(i, N - 1){
        if (a.at(i) >= x){cnt += (a.at(i) - x); a.at(i) = x;}
        ll b = a.at(i) + a.at(i + 1);
        if (b >= x){
            ll c = b - x;
            if (c >= a.at(i + 1)){
                cnt += a.at(i + 1);
                a.at(i + 1) = 0;
            } else {
                cnt += c;
                a.at(i + 1) -= c;
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
