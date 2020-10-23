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
    string S; cin >> S;
    ll cnt[2][2]; // first row is for 0 (mod2), first column is for 0
    rep(i, 2){rep(j, 2){cnt[i][j] = 0;}}
    rep(i, S.size()){
        cnt[i % 2][S[i] - '0'] += 1;
    }
    ll bw = cnt[0][0] + cnt[1][1];
    ll wb = cnt[0][1] + cnt[1][0];
    if (bw > wb){cout << S.size() - bw << endl;} else {cout << S.size() - wb << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
