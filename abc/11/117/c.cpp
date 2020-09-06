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
    vector<ll> X(M); rep(i, M){cin >> X.at(i);}
    sort(X.begin(), X.end());
    // 分割が決まればコストは定まる(組の中で一番左からスタートして右へ移動)
    if (N >= M){
        cout << 0 << endl;
    } else {
        priority_queue<int> q;
        // 駒が1つなら自分でこの距離を全部歩く必要がある
        // 駒が1つ追加されると，一つ動かなければいけない区間が減る(ここで一番長い区間を切る)
        ll ans = X.at(M-1) - X.at(0);
        rep(i, M-1){q.push(X.at(i+1) - X.at(i));}
        rep(i, N-1){auto v = q.top(); q.pop(); ans -= v;}
        cout << ans << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
