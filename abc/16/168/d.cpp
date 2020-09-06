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
    ll N, M; cin >> N >> M;
    vector<vector<ll>> edges(N);
    rep(i, M){
        ll a, b; cin >> a >> b; a--; b--;
        edges.at(a).push_back(b);
        edges.at(b).push_back(a);
    }
    queue<P> q;
    vector<ll> sign(N, INF);
    set<P> used;

    q.push(make_pair(0, 0)); // (from, dest)
    ll cnt = 0;
    // 幅優先探索
    while (q.size() > 0){
        P next = q.front();
        ll dest = next.second;
        ll from = next.first;
        q.pop();
        if (sign.at(dest) == INF){sign.at(dest) = from;} // might be visited twice
        for (ll i: edges.at(dest)){
            if (sign.at(i) == INF && used.find(make_pair(dest, i)) == used.end()){
                used.insert(make_pair(dest, i));
                used.insert(make_pair(i, dest));
                q.push(make_pair(dest, i));
            }
        }
        cnt++;
    }
    cout << "Yes" << endl;
    rep(i, N - 1){
        cout << sign.at(i + 1) + 1 << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
