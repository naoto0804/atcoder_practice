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
const int dx[3] = {-1, 0, -1};
const int dy[3] = {0, -1, -1};
// const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

// 約数列挙
vector<ll> divisor(ll N) {
    vector<ll> res;
    for (ll i = 1L; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            ll j = N / i;
            if (j != i)  {
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}



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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    Dijkstra dijkstra(2 * 100);
    rep(i, 99){
        // 階段
        dijkstra.add_edge(i, i + 1, y);
        dijkstra.add_edge(i + 1, i, y);
        dijkstra.add_edge(i + 100, i + 100 + 1, y);
        dijkstra.add_edge(i + 100 + 1, i + 100, y);
        dijkstra.add_edge(i + 1, i + 100, x);
        dijkstra.add_edge(i + 100, i + 1, x);
    }
    rep(i, 100){
        dijkstra.add_edge(i, i + 100, x);
        dijkstra.add_edge(i + 100, i, x);
    }

    dijkstra.exec(a - 1);
    cout << dijkstra.get_cost(b + 99) << '\n';
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
