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
    ll N; cin >> N;
    vector<ll> A(N), B(N), C(N);
    rep(i, N){cin >> A.at(i);}
    rep(i, N){cin >> B.at(i);}
    rep(i, N){cin >> C.at(i);}
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    for (auto b: B){
        auto a_iter = lower_bound(A.begin(), A.end(), b);
        auto c_iter = upper_bound(C.begin(), C.end(), b);
        // cout << b << " " << distance(A.begin(), a_iter) << " " << distance(c_iter, C.end()) << endl;
        ans += distance(A.begin(), a_iter) * distance(c_iter, C.end());
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
