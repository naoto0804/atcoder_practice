// ctrl+shift+b
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
    vector<P> X;
    rep(i, N){
        ll x, y; cin >> x >> y;
        X.push_back(make_pair(x, y));
    }
    // N = 100 なので3つ選ぶ組み合わせは全て試す
    // 一つの点を原点に揃えると形の詳細を無視して面積公式で押し切れる
    ll cnt = 0;
    rep(i, N){
        rep(j, N){
            rep(k, N){
                if (i >= j or i >= k or j >= k){continue;}
                ll x1 = X.at(i).first, y1 = X.at(i).second;
                ll x2 = X.at(j).first - x1, y2 = X.at(j).second - y1;
                ll x3 = X.at(k).first - x1, y3 = X.at(k).second - y1;
                ll area = x2 * y3 - x3 * y2;
                if (area != 0 && area % 2 == 0){cnt++;}
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
