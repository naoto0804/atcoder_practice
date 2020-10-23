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
    ll N, M, X; cin >> N >> M >> X;
    vector<ll> C(N);
    vector<vector<ll>> A(N);
    rep(i, N){
        cin >> C.at(i);
        rep(j, M){ll tmp; cin >> tmp; A.at(i).push_back(tmp);}
    }

    ll ans = INF;
    for (ll bit = 0; bit < (1<<N); ++bit) { // 1を左に2回シフトすると100
        vector<ll> S;
        for (ll i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
        vector<ll> level(M); rep(i, M){level.at(i) = 0;}
        ll cost = 0;
        for (auto v: S){
            cost += C.at(v);
            rep (i, M){
                level.at(i) += A.at(v).at(i);
            }
        }

        // check
        bool flag = true;
        rep(i, M){if (level.at(i) < X){flag = false; break;}}
        if (flag){
            if (cost < ans){ans = cost;}
        }
    }
    ll out = (ans < INF) ? ans : -1;
    cout << out << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
