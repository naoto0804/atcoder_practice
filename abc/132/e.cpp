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
    // ループを回り始めるとややこしすぎるので，移動回数を3で割った余りに注目してノードを3つもつ
    ll N, M; cin >> N >> M;
    Graph g(3 * N, vector<ll>());

    rep(i, M){
        ll u, v; cin >> u >> v; u--; v--;
        g[3 * u].push_back(3 * v + 1);
        g[3 * u + 1].push_back(3 * v + 2);
        g[3 * u + 2].push_back(3 * v);
    }
    ll S, T; cin >> S >> T; S--; T--;
    // ll ans = search(g, 3 * S, 3 * T, 0);
    // ans = (ans == INF) ? -1 : ans / 3;
    // cout << ans << endl;

    vector<ll> depth(3 * N, INF);
    queue<ll> q;
    q.push(3 * S);
    depth.at(3 * S) = 0;

    while (q.size() > 0){
        ll cur = q.front();
        q.pop();
        for (auto next: g[cur]){
            if (depth.at(next) == INF){
                depth.at(next) = depth.at(cur) + 1;
                q.push(next);
            }
        }
    }

    if (depth.at(3 * T) == INF){
        cout << -1 << endl;
    } else {
        cout << depth.at(3 * T) / 3 << endl;
    }
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
