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
    ll N, T; cin >> N >> T;
    ll ans = 0, cnt = 0;
    vector<ll> A(N), acc_min(N); // この地点までの最小値を保存しておく
    rep(i, N){
        cin >> A.at(i);
        if (i == 0){
            acc_min.at(i) = A.at(i);
        } else {
            acc_min.at(i) = (A.at(i) < acc_min.at(i - 1)) ? A.at(i) : acc_min.at(i - 1);
        }
    }
    ll zero = 0;
    rep(i, N - 1){
        ll tmp = max((ll) 0, A.at(i + 1) - acc_min.at(i)); // ここで売るとしたらいくらか？
        if (tmp > ans){
            ans = tmp; cnt = 1;
        } else if (tmp == ans){
            cnt++;
        }
    }
    // 以上で列挙したポイントのスコアを1ずつ動かせば終了なので
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
