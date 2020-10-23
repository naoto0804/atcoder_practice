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

/**
 * ランレングス圧縮
 */
vector<pair<char, ll>> RLE(const string &S) {
    ll cnt = 0;
    vector<pair<char, ll>> res;
    for (ll i = 0; i < (ll) S.size(); i++) {
        cnt++;
        if (i == (ll) S.size() - 1) {
            res.emplace_back(S[i], cnt);
            break;
        }
        if (S[i] != S[i + 1]) {
            res.emplace_back(S[i], cnt);
            cnt = 0;
        }
    }
    return res;
}

void Main() {
    string s; cin >> s;
    ll x, y; cin >> x >> y;
    vector<pair<char, ll>> z = RLE(s);

    // ナイーブ解法: dp(i,x,y,k) = i文字目の命令後に座標x,yに向きkでいられるか -> O(N^3)
    // スマートな解法: Fが連続する区間を圧縮 + x方向だけ,y方向だけに分割

    vector<set<ll>> dpx, dpy;
    set<ll> tmp; tmp.insert(0);
    dpx.push_back(tmp); dpy.push_back(tmp);

    bool dir_now_x = true;
    rep(i, z.size()){
        if (z[i].first == 'T'){
            if (z[i].second % 2 == 1){dir_now_x = !dir_now_x;}
        } else {
            set<ll> tmp;
            if (i == 0){
                for (auto a: dpx.at(dpx.size() - 1)){tmp.insert(a + z[i].second);}
                dpx.push_back(tmp);
            } else {
                if (dir_now_x){
                    for (auto a: dpx.at(dpx.size() - 1)){tmp.insert(a + z[i].second); tmp.insert(a - z[i].second);}
                    dpx.push_back(tmp);
                } else {
                    for (auto a: dpx.at(dpy.size() - 1)){tmp.insert(a + z[i].second); tmp.insert(a - z[i].second);}
                    dpy.push_back(tmp);
                }
            }
        }
    }
    set <ll> last_x = dpx.at(dpx.size() - 1), last_y = dpy.at(dpy.size() - 1);
    if (last_x.find(x) != last_x.end() && last_y.find(y) != last_y.end()){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
