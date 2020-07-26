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

// searchに色々渡しすぎるとOOMになるので要注意
Graph graph;
vector<ll> f, g;
vector<bool> visited;

void search(ll prev, ll cur){
    ll tmp_f = 1, tmp_g = 1;
    for (auto ind: graph[cur]){
        if (ind != prev){
            if (f.at(ind) == -INF){search(cur, ind);}
            tmp_f = tmp_f * g.at(ind) % MOD;
            tmp_g = tmp_g * f.at(ind) % MOD;
        }
    }
    g.at(cur) = tmp_g;
    f.at(cur) = (g.at(cur) + tmp_f) % MOD;
}

void Main() {
    ll N; cin >> N;
    rep(i, N){vector<ll> dummy; graph.push_back(dummy);}
    // f(x) xを親とする部分木が条件を満たすパターン
    // g(x) xを必ず白で塗り，さらに部分木が条件を満たす
    // f(x) = g(x) + g(y1) * g(y2) * ...
    // g(x) = f(y1) * f(y2) * ..
    rep(i, N - 1){
        ll a, b; cin >> a >> b; a--; b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    rep(i, N){f.push_back(-INF); g.push_back(INF); visited.push_back(false);}
    search(0, 0);
    cout << f.at(0) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
