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
    // naiveにやるとNQ回で間に合わない
    // 各ノードへの加算を保持し，最後に親の値を子に足すのを最後のノードまで繰り返す

    int N, Q;
    Graph graph(N);
    cin >> N >> Q;

    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll cnt[N];
    bool used[N];
    rep(i, N){cnt[i] = 0; used[i] = false;}
    rep(i, Q){
        int p, x;
        cin >> p >> x;
        p--;
        cnt[p] += x;
    }

    queue<P> q;
    q.push(make_pair(0, 0));
    while (q.size() > 0){
        auto p = q.front();
        q.pop();
        used[p.second] = true;
        if (p.second != 0){cnt[p.second] += cnt[p.first];}
        for (auto v : graph[p.second]){
            if (!used[v]){q.push(make_pair(p.second, v));}
        }
    }
    rep(i, N){cout << cnt[i] << " "; }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
