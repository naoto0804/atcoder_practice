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
    ll H, W; cin >> H >> W;
    ll a[H][W];
    rep(i, H){rep(j, W){
        char c; cin >> c;
        if (c == '#'){
            a[i][j] = 1;
        } else {
            a[i][j] = 0;
        }
    }}
    vector<ll> xcoords, ycoords;
    rep(i, H){
        ll tmp = 0;
        rep(j, W){tmp += a[i][j];}
        if (tmp != 0){ycoords.push_back(i);}
    }
    rep(j, W){
        ll tmp = 0;
        rep(i, H){tmp += a[i][j];}
        if (tmp != 0){xcoords.push_back(j);}
    }
    for (auto y: ycoords){
        for (auto x: xcoords){
            if (a[y][x]){cout << "#";} else {cout << ".";}
        }
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
