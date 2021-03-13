// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll> >;
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
    ll N; cin >> N;
    vector<string> vs;
    rep(i, N){
        string s; cin >> s; vs.push_back(s);
        // rep(j, N){
        //     switch(s[j]){
        //         case 'B':
        //             break;
        //         case 'W':
        //             break;
        //         default:
        //     }
        // }
    }

    mf_graph<ll> graph(N * N + 2);
    ll S = N * N;
    ll T = S + 1;

    // どれだけ下がってしまうかの(隣接が一緒の色だと+1)をいかに少なくするか考えるとmaxflow/mincutに落ちる
    rep(i, N){rep(j, N){
        ll x = i * N + j;
        if ((i + j) % 2 == 0){
            switch(vs.at(i)[j]){
                case 'B':
                    // 必ず x -> Tを選んでもらう
                    graph.add_edge(S, x, INF);
                    graph.add_edge(x, T, 0);
                    break;
                case 'W':
                    // 必ず S -> xを選んでもらう
                    graph.add_edge(S, x, 0);
                    graph.add_edge(x, T, INF);
                    break;
                default:
                    graph.add_edge(S, x, 0);
                    graph.add_edge(x, T, 0);
            }
        } else {
            // oddとevenのgridでは逆にやるとうまく制約が表現できる
            switch(vs.at(i)[j]){
                case 'B':
                    graph.add_edge(S, x, 0);
                    graph.add_edge(x, T, INF);
                    break;
                case 'W':
                    graph.add_edge(S, x, INF);
                    graph.add_edge(x, T, 0);
                    break;
                default:
                    graph.add_edge(S, x, 0);
                    graph.add_edge(x, T, 0);
            }
        }
    }}
    rep(i, N){
        rep(j, N - 1){
            ll x = i * N + j;
            graph.add_edge(x, x + 1, 1);
            graph.add_edge(x + 1, x, 1);
        }
    }
    rep(j, N){
        rep(i, N - 1){
            ll x = i * N + j;
            graph.add_edge(x, x + N, 1);
            graph.add_edge(x + N, x, 1);
        }
    }

    cout << 2 * N * (N - 1) - graph.flow(S, T) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
