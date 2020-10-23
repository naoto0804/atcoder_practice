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
    int N;
    cin >> N;
    ll arr[10][10];
    rep(i, 10){rep(j, 10){arr[i][j] = 0;}}
    ll ans = 0;
    rep2(i, 1, N + 1){
        string num = to_string(i);
        int ind_i = num[0] - '0';
        int ind_j = num[num.size() - 1] - '0';
        arr[ind_i][ind_j] += 1;
    }
    rep(i, 10){rep(j, 10){ans += arr[i][j] * arr[j][i];}}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
