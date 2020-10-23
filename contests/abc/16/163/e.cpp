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

class CompareFirst
{
public:
  bool operator()(P n1, P n2) {
    // return n1.first>n2.first; //>:降順　pairのfirst同士を比較する
    return n1.first < n2.first;
  }
};

void Main() {
    int N;
    cin >> N;
    priority_queue<P, vector<P>, CompareFirst> q;
    rep(i, N){
        ll a;
        cin >> a;
        q.push(make_pair(a, i)); // (score, ind)
    }

    ll dp[N+1][N+1];  // dp[j][k]はi=j+k人をj人左に，k人右に配置
    rep(i, N+1){rep(j, N+1){dp[i][j] = 0;}}
    rep2(i, 1, N+1){
        auto p = q.top();
        q.pop();
        ll score = p.first;
        ll ind = p.second;
        rep(j, i+1){
            ll k = i - j;
            cout << j << " " << k << endl;
            if (k - 1 >= 0) {dp[j][k] = max(dp[j][k], dp[j][k - 1] + score * abs(((N - 1) - (k - 1)) - ind));} // 右に挿入, (端点の処理に注意，，)
            if (j - 1 >= 0) {dp[j][k] = max(dp[j][k], dp[j - 1][k] + score * abs(ind - (j - 1)));} // 左に挿入
        }
    }
    ll ans = 0;
    rep(i, N+1){
        if (dp[i][N-i] > ans){ans = dp[i][N-i];}
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
