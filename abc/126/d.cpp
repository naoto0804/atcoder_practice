#include "template.hpp"

void solve(int N, vi &u, vi &v, vi &w)
{
    vector<vector<ii>> nxt(N);
    rep(i, N - 1)
    {
        nxt[u[i]].emplace_back(v[i], w[i]);
        nxt[v[i]].emplace_back(u[i], w[i]);
    }
    queue<ii> q;
    q.emplace(0, 0);
    vi visited(N, INT_MAX);
    while (!q.empty())
    {
        int u = q.front().first, d = q.front().second;
        q.pop();
        if (visited[u] != INT_MAX)
            continue;
        visited[u] = d % 2;
        for (auto &p : nxt[u])
        {
            int v = p.first, d2 = p.second;
            q.emplace(v, d + d2);
        }
    }
    rep(i, N)
    {
        printf("%d\n", visited[i]);
    }
}

int main()
{
    int N;
    scanf("%d%*c", &N);
    vi u(N - 1), v(N - 1), w(N - 1);
    rep(i, N - 1)
    {
        scanf("%d %d %d%*c", &u[i], &v[i], &w[i]);
        u[i]--;
        v[i]--;
        w[i] %= 2;
    }
    solve(N, u, v, w);
    return 0;
}
