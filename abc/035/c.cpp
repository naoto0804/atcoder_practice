// ctrl+shift+b
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
    // いもす法
    // 加算: 区間[l, r]にvだけ加算
    // 構築: 取得のための前処理
    // 取得: 構築が完了しているときにある位置の値を求める
    // 加算O(1), 構築O(N), 取得O(1)
    ll N, Q; cin >> N >> Q;
    vector<ll> X(N, 0), acc_X(N);
    rep(i, Q){
        ll l, r; cin >> l >> r; l--; r--;
        X.at(l) += 1;
        if (r + 1 <= N - 1){X.at(r + 1) -= 1;}
    }
    acc_X.at(0) = X.at(0);
    rep(i, N - 1){acc_X.at(i + 1) = acc_X.at(i) + X.at(i + 1);}
    // rep(i, N){cout << acc_X.at(i) << endl;}
    rep(i, N){cout << acc_X.at(i) % 2;}
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
