#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define rrep(i, n, m) for (ll i = n; i >= (ll)(m); i--)
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

void Main()
{
    ll N;
    cin >> N;
    vector<vector<int>> G(N);
    vector<pair<int, int>> vp;
    rep(i, N)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
        vp.emplace_back(a, b);
    }
    int K = 0; // 次数の最大値の管理
    map<pair<int, int>, int> I;
    vector<int> cs(N, 0); // color of edge between its parent

    // node番号0を根とした木とみなして，幅優先探索(BFS)
    vector<int> used(N, 0);
    queue<int> que;
    used[0] = 1;
    que.emplace(0);

    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        if (K < (int)G[v].size())
            K = G[v].size();
        int cur = 1;
        // vからuにエッジを貼る時は，できるだけ小さい色で貼る
        for (int u : G[v])
        {
            if (used[u])
                continue;
            if (cur == cs[v])
                cur++;
            cs[u] = I[make_pair(u, v)] = I[make_pair(v, u)] = cur++;
            used[u] = 1;
            que.emplace(u);
        }
    }

    cout << K << endl;
    for (auto p : vp)
        cout << I[p] << endl;
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
