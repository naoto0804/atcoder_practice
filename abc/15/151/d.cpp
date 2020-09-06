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
    int H, W;
    cin >> H >> W;
    int board[H][W];
    rep(i, H){rep(j, W){
        char x;
        cin >> x;
        if (x == '.'){board[i][j] = 1;} else {board[i][j] = 0;}
    }}

    ll total_ans = 0;

    // BFS(幅優先探索)
    rep(i, H){rep(j, W){
        if (!board[i][j]){continue;}
        ll dist[H][W];
        int cnt = 0;
        rep(k, H){rep(l, W){dist[k][l]=INF;}}

        queue<tuple<int, int, int>> fifo;
        fifo.push(make_tuple(i, j, 0));

        while (fifo.size() > 0){
            tuple<int, int, int> tmp = fifo.front();
            int& cur_y = get<0>(tmp);
            int& cur_x = get<1>(tmp);
            int& cur_cost = get<2>(tmp);
            fifo.pop();
            cnt += 1;
            if (dist[cur_y][cur_x] != INF){continue;} // 足切り(もうpopしている解がもう一回出てしまうことがある．その時にその先の遷移を足すと指数関数的に増えてしまう)
            dist[cur_y][cur_x] = cur_cost;

            rep(k, 4){
                int next_y = cur_y + dy[k];
                int next_x = cur_x + dx[k];
                if (0 <= next_y && next_y < H && 0 <= next_x && next_x < W && dist[next_y][next_x] == INF && board[next_y][next_x]){
                    // cout << next_y << " " << next_x << " " << dist[next_y][next_x] << " " << board[next_y][next_x] << endl;
                    fifo.push(make_tuple(next_y, next_x, cur_cost + 1));
                }
            }
        }
        ll ans = 0;
        rep(k, H){rep(l, W){
            if (dist[k][l] != INF and dist[k][l] > ans){ans = dist[k][l];}
        }}
        if (ans != INF and ans > total_ans){total_ans = ans;}
        // cout << i << " " << j << " count: " << cnt << endl;
    }}
    cout << total_ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
