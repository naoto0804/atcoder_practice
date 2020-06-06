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

ll dfs(int K, const Graph&graph, int now,int from) {
    int can_use_color_num;

    if (from == -1){
        can_use_color_num = K - 1;
    } else {
        can_use_color_num = K - 2;
    }

    if (K < graph[now].size()){
        return 0;
    } else {
        ll case_num = 1;
        for (auto e: graph[now]){
            if (e == from){continue;}
            case_num *= can_use_color_num;
            can_use_color_num--;
            case_num %= MOD;
        }
        for (auto e: graph[now]){
            if (e == from){continue;}
            case_num *= dfs(K, graph, e, now);
            case_num %= MOD;
        }
        return case_num;
    }
}

void Main() {
    ll N, K; cin >> N >> K;
    // Graph graph(N, vector<ll>(N, INF));
    Graph g(N);
    rep(i, N - 1){
        ll a, b; cin >> a >> b;
        a--; b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    // 頂点0を根とする根付き木と考える，ある頂点とその親が既に塗られれている時，xの個の数c_{x}について塗り分け方は(K-2)P(c_{x})
    ll ans = K * dfs(K, g, 0, -1);
    cout << ans % MOD << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
