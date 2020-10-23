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

/**
 * Library
 * --------------------------------------------------------
 */

/**
 * ワーシャルフロイド法
 * 隣接行列で受け取り、全頂点間最短経路を算出
 */
void warshall_floyd(Graph &graph) {
    int V = graph.size();
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}
/**
 * --------------------------------------------------------
 */

/**
 * https://atcoder.jp/contests/abc073/submissions/7665203
 * ABC 073 D - joisino's travel
 */
void Main() {
    int H, W;
    cin >> H >> W;

    // vector<vector<int>> c(10, vector<int>(10));
    // rep(i, 10){rep(j, 10){int tmp; cin >> tmp; c[i].push_back(tmp);}}

    Graph graph(10, vector<ll>(10, INF));
    rep(i, 10) {
        rep(j, 10) {
            int tmp;
            cin >> tmp;
            graph[i][j] = tmp;
        }
    }
    warshall_floyd(graph);

    ll ans = 0;
    rep(i, H) {rep(j, W) {int a; cin >> a; if (a != -1){ans += graph[a][1];}}}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
