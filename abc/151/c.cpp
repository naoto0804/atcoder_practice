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
    ll N, M;
    cin >> N >> M;
    // vector<P> S(N);
    vector<ll> ac(N, 0), wa(N, 0);
    rep(i, M){
        ll p; string S;
        cin >> p >> S;
        p--;
        if (S == "AC"){
            ac.at(p) += 1;
        } else {
            if (ac.at(p) == 0){
                wa.at(p) += 1;
            }
        }
    }
    ll n_correct = 0;
    ll n_fail = 0;
    rep(i, N){
        if (ac.at(i) > 0){
            n_correct += 1;
            n_fail += wa.at(i);
        }
    }
    cout << n_correct << " " << n_fail << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
