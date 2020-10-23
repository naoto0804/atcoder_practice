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
    // nが出るにはその色でn-1が出ていなければいけない→今n回出ている色の個数をカウント，cnt[n-1]が1ならその色を使う，2なら2通り，...となって
    // 左から一個ずつ足していった時に遷移はただのかけ算に落とし込める
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N){cin >> A.at(i);}
    map<ll, ll> cnt;
    cnt[-1] = 3;
    ll ans = 1;
    rep(i, N){
        ll cur = A.at(i);
        ll prev = A.at(i) - 1;
        ans = ans * cnt[prev] % MOD;
        if (cnt.find(A.at(i)) != cnt.end()){
            cnt[cur]++; cnt[prev]--;
        } else {
            cnt[cur] = 1; cnt[prev]--;
        }
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
