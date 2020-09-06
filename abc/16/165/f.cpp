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

ll N;
vector<ll> ans, A;
Graph UV;
void search(ll pos, vector<ll> dp, vector<bool> visited){
    // dp[i]: 長さi+1の最長部分増加列がある時，その右端の最小値
    vector<ll> new_dp(dp);
    vector<bool> new_visited(visited);
    new_visited.at(pos) = true;

    auto left_iter = lower_bound(new_dp.begin(), new_dp.end(), A[pos]);
    auto right_iter = upper_bound(new_dp.begin(), new_dp.end(), A[pos]);
    if (distance(left_iter, right_iter) == 0){ // 重複は許されない
        new_dp.at(distance(new_dp.begin(), left_iter)) = A.at(pos);
    }

    auto iter = lower_bound(new_dp.begin(), new_dp.end(), INF);
    ll cnt = distance(new_dp.begin(), iter);
    ans.at(pos) = cnt;
    for (auto v: UV.at(pos)){
        if (!visited[v]){search(v, new_dp, new_visited);}
    }
    return;
}

void Main() {
    cin >> N;
    rep(i, N){ll a; cin >> a; A.push_back(a);}
    rep(i, N){vector<ll> tmp(0); UV.push_back(tmp); ans.push_back(INF);}
    rep(i, N-1){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        UV.at(u).push_back(v);
        UV.at(v).push_back(u);
    }
    vector<ll> dp(N, INF);
    vector<bool> visited(N, false);
    search(0, dp, visited);
    rep(i, N){cout << ans.at(i) << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
