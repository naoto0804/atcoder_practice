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
    ll H, W; cin >> H >> W;
    ll bw[H][W];
    ll ids[H][W]; rep(i, H){rep(j, W){ids[i][j] = INF;}}

    rep(i, H){
        string s; cin >> s;
        rep(j, W){if (s[j] == '#'){bw[i][j] = 1;}else{bw[i][j] = 0;}}
    }

    ll id = 0;
    rep(i, H){rep(j, W){
        if (ids[i][j] != INF){continue;}
        stack<P> q; q.push(make_pair(i, j)); // DO DFS

        while (q.size() > 0){
            P p = q.top();
            q.pop();
            ll cur_i = p.first;
            ll cur_j = p.second;

            ids[cur_i][cur_j] = id;

            rep(k, 4){
                ll next_i = cur_i + dy[k];
                ll next_j = cur_j + dx[k];
                if (0 <= next_i && next_i < H && 0 <= next_j && next_j < W){
                    if (bw[cur_i][cur_j] == 1 - bw[next_i][next_j] && ids[next_i][next_j] == INF){
                        // cout << i << " " << j << " " << next_i << " " << next_j << endl;
                        q.push(make_pair(next_i, next_j));
                    }
                }
            }
        }
        id++;
    }}

    map<ll, P> counter; rep(i, id){counter[i] = make_pair(0, 0);}
    rep(i, H){
        rep(j, W){
            // cout << ids[i][j] << " ";
            if (bw[i][j]){
                counter[ids[i][j]].first++;
            } else {
                counter[ids[i][j]].second++;
            }
        }
    }
    ll ans = 0;
    rep(i, id){ans += counter[i].first * counter[i].second;}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
