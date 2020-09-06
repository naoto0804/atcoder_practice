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
    string S; cin >> S;
    ll N = S.size();

    ll MOD = 2019;

    // (i, j)が条件を満たすのは a_{j} + 10 * a_{j-1} + .... + 10^{j-i}*a_{i} が2019の倍数の時
    //　左からk+1文字目以降の整数を値とみなしたときの数字をTkとすると，(i, j)が条件を満たすのは 10^{n-j}(T_{i-1} - T_{j})が2019の倍数のとき
    // 10はmod2019で逆元が存在するので，T_{i-1} == T_{j} (mod2019)なら良い

    vector<vector<ll>> modind(MOD);
    modind.at(0).push_back(0);
    ll num = 0;

    vector<ll> x(N);
    x.at(0) = 1;
    rep(i, N-1){x.at(i+1) = x.at(i) * 10 % MOD;} // 10のn乗をダイレクトに計算すると桁あふれする -> 10をかけるたびにMODを取る

    rep(i, N){
        num += (S[N-1-i] - '0') * x.at(i) % MOD;
        modind.at(num % 2019).push_back(i + 1);
    }
    ll ans = 0;
    rep(i, MOD){
        ll size = modind.at(i).size();
        if (size >= 2){ans += size * (size - 1) / 2;}
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
