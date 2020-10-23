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
    vector<ll> X(N); rep(i, N){cin >> X.at(i);}
    vector<ll> sorted_X(X.size()); copy(X.begin(), X.end(), sorted_X.begin());
    sort(sorted_X.begin(), sorted_X.end());

    // 中央値候補は sorted_X.at(N / 2 - 1), sorted_X.at(N / 2) のどちらか
    rep(i, N){
        if (X.at(i) <= sorted_X.at(N / 2 - 1)){
            cout << sorted_X.at(N / 2) << endl;
        } else {
            cout << sorted_X.at(N / 2 - 1) << endl;
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
