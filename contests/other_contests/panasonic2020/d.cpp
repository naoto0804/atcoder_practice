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
    map<ll, vector<pair<string, ll>>> x;
    // (現状の文字列，今までに使った文字で一番大きいもの(aが1,bが2,..))
    x[1].push_back(make_pair("a", 1));
    rep(i, N - 1){
        for (auto a: x[i + 1]){
            rep(j, a.second){
                x[i + 2].push_back(make_pair(a.first + (char)('a' + j), a.second));
            }
            x[i + 2].push_back(make_pair(a.first + (char)('a' + a.second), a.second + 1));
        }
    }
    for (auto a: x[N]){cout << a.first << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
