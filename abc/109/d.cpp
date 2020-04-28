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
    int H, W; cin >> H >> W;
    int a[H][W]; rep(i, H){rep(j, W){cin >> a[i][j];}}

    // 一筆書きの経路を作り，あとは条件に沿うように移動していけばいずれ見つかる
    vector<P> route;
    rep(i, H){
        if (i % 2 == 0){
            rep(j, W){route.push_back(make_pair(i, j));}
        } else {
            rep(j, W){route.push_back(make_pair(i, (W-1)-j));}
        }
    }

    using quadruplet = tuple<int, int, int, int>;
    vector<quadruplet> ans;
    rep(i, route.size() - 1){
        ll prev_y = get<0>(route.at(i)), prev_x = get<1>(route.at(i));
        ll next_y = get<0>(route.at(i+1)), next_x = get<1>(route.at(i+1));
        if (a[prev_y][prev_x] % 2 == 1){
            ans.push_back(make_tuple(prev_y+1, prev_x+1, next_y+1, next_x+1));
            a[prev_y][prev_x]--;
            a[next_y][next_x]++;
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size()){
        quadruplet q = ans.at(i);
        cout << get<0>(q) << " " << get<1>(q) << " " << get<2>(q) << " " << get<3>(q) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
