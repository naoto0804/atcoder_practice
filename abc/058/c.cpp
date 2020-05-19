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
    ll n; cin >> n;
    vector<vector<ll>> cnt(26, vector<ll>(n, 0));
    rep(i, n){
        string s;
        cin >> s;
        rep(j, s.size()){cnt[s[j] - 'a'][i] += 1;}
    }
    // rep(i, n){
    //     rep(j, 26){cout << cnt[j][i] << " ";}
    //     cout << endl;
    // }
    rep(j, 26){
        ll tmp = *min_element(cnt[j].begin(), cnt[j].end());
        rep(i, tmp){
            char c = 'a' + j;
            cout << c;
        }
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
