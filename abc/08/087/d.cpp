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
    Graph g; rep(i, N){vector<ll> tmp; g.push_back(tmp);}
    map<ll, map<ll, ll>> m;

    rep(i, M){
        ll l, r, d; cin >> l >> r >> d; l--; r--;
        m[l][r] = d; // 2個目の場所-1個目の場所が距離
        m[r][l] = -d;
    }

    set<ll> not_visited; rep(i, N){not_visited.insert(i);}
    map<ll, ll> coords;

    bool flag = true;
    // 複数の集合に別れている可能性を考慮
    while (not_visited.size() > 0 && flag){
        ll start_ind = *not_visited.begin(); not_visited.erase(start_ind);
        stack<int> q; q.push(start_ind); coords[start_ind] = 0;

        // 始点を決めて深さ優先探索
        while (q.size() > 0 && flag){
            ll ind = q.top();
            q.pop();
            for (auto a: m[ind]){ // indからedgeがあるind'に対して
                if (coords.find(a.first) != coords.end()){ // そこの座標が確定している時矛盾が無いか確認
                    if (m[ind][a.first] != (coords[a.first] - coords[ind])){flag = false; break;}
                } else { // 確定していない時は確定させる
                    coords[a.first] = coords[ind] + m[ind][a.first];
                }

                // ind'を一度も訪れていない時，stackに追加
                if (not_visited.find(a.first) != not_visited.end()){
                    q.push(a.first);
                    not_visited.erase(a.first);
                }
            }
        }
    }
    string ans = flag ? "Yes" : "No";
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
