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
    int N, K;
    cin >> N >> K;

    // K回の操作中，i回まず取り出して，そのうち価値が小さい方からK-i回戻す(i >= K-i)
    vector<ll> V(N); rep(i, N){cin >> V.at(i);}
    ll ans = 0;
    rep(a, K+1){rep(b, K+1){
        if ((a + b) > min(N, K)){continue;} // 取り出し回数の限界はmin(N, K)
        ll max_cd = K - (a + b);
        ll left = 0;
        ll right = N-1;
        priority_queue< ll, vector<ll>, greater<ll> > q;
        for(ll i=0;i<(ll)(a);i++){q.push(V.at(i));}
        for(ll i=N-1;i>(ll)(N-1-b);i--){q.push(V.at(i));}
        rep(i, max_cd){
            if (q.size() == 0){break;}
            ll x = q.top();
            if (x < 0){q.pop();} else {break;}
        }
        ll tmp_ans = 0;
        while(q.size() > 0){tmp_ans += q.top(); q.pop();}
        if (tmp_ans > ans){ans = tmp_ans;}
    }}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
