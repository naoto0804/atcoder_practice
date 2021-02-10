// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define rrep(i, n, m) for (ll i = n; i >= (ll)(m); i--)
// const int dx[3] = {-1, 0, -1};
// const int dy[3] = {0, -1, -1};
// const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddx[4] = {0, 1, 0, -1};
const int ddy[4] = {1, 0, -1, 0};
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
 * Library
 * --------------------------------------------------------
 */
struct edge {
    int from, to;
    ll cost;
};

class Dijkstra {
    int V;
    vector<vector<edge>> edges;
    vector<ll> dist;
    vector<ll> prev;
    vector<ll> route_count;

public:
    Dijkstra(int v) : V(v) {
        edges.resize(V);
        dist.resize(V, INF);
        prev.resize(V, INF);
        route_count.resize(V, 0);
    }

    void add_edge(int from, int to, ll cost) {
        edges[from].push_back({from, to, cost});
    }

    /**
     * @param goal 0-indexed
     * @return return cost to reach the goal. return INF if the goal is unreachable.
     */
    ll get_cost(int goal) {
        return dist[goal];
    }

    /**
     * @param goal 0-indexed
     * @return return total route count to reach the goal ( result value % MOD )
     */
    ll get_route_count(int goal) {
        return route_count[goal];
    }

    /**
     * @param goal 0-indexed
     * @return return route from start to goal
     */
    vector<ll> get_route(int goal) {
        vector<ll> res;
        res.push_back(goal);
        ll dest = goal;
        while (prev[dest] != INF) {
            res.push_back(prev[dest]);
            dest = prev[dest];
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void exec(int start) {
        dist[start] = 0;
        route_count[start] = 1;
        priority_queue<P, vector<P>, greater<>> queue;
        queue.push({dist[start], start});
        while (!queue.empty()) {
            P p = queue.top();
            queue.pop();
            ll prev_cost = p.first;
            ll src = p.second;
            if (dist[src] < prev_cost) continue;

            for (edge &e : edges[src]) {
                ll to = e.to;
                ll cost = e.cost;
                if (cost != INF && dist[to] > dist[src] + cost) {
                    dist[to] = dist[src] + cost;
                    queue.push({dist[to], to});
                    prev[to] = src;
                    route_count[to] = route_count[src];
                } else if (dist[to] == dist[src] + cost) {
                    route_count[to] += route_count[src];
                    route_count[to] %= MOD;
                }
            }
        }
    }
};
/**
 * --------------------------------------------------------
 */

/**
 * ABC 035 D - トレジャーハント
 * https://atcoder.jp/contests/abc035/submissions/7668866
 */
void Main() {
    int H, W;
    cin >> H >> W;
    Dijkstra dijkstra(H * W + 26);
    bool board[H][W];
    ll start, goal;
    rep(i, H){
        string s; cin >> s;
        rep(j, W){
            if (s[j] == '#'){board[i][j] = false;} else {board[i][j] = true;}

            if (s[j] == 'S'){start = i * W + j;}
            else if (s[j] == 'G'){goal = i * W + j;}

            ll a_ind = s[j] - 'a';
            if (0 <= a_ind && a_ind < 26){
                // テレポートを表現 a->Aがコスト1, A->aがコスト0とすると丸く収まる
                dijkstra.add_edge(i * W + j, H * W + a_ind, 1);
                dijkstra.add_edge(H * W + a_ind, i * W + j, 0);
            }
        }
    }
    rep(i, H){
        rep(j, W){
            if (!board[i][j]){continue;}
            rep(k, 4){
                ll y = i + ddy[k];
                ll x = j + ddx[k];
                if (0 <= x && x < W && 0 <= y && y < H && board[y][x]){dijkstra.add_edge(i * W + j, y * W + x, 1);}
            }
        }
    }
    dijkstra.exec(start);
    ll cost = dijkstra.get_cost(goal);
    if (cost == INF){
        cout << -1 << endl;
    } else {
        cout << cost << endl;
    }
}


int main()


{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
