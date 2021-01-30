// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define rrep(i, n, m) for (ll i = n; i >= (ll)(m); i--)
const int dx[3] = {-1, 0, -1};
const int dy[3] = {0, -1, -1};
// const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

// https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
void Main()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) { cin >> a.at(i); }

    // rep(k, N)
    // {
    //     if (k > 0){rotate(a.begin(), a.begin() + 1, a.end());}
    //     fenwick_tree<ll> fw(N);
    //     ll ans = 0;
    //     rep(i, N){
    //         ans += i - fw.sum(0, a[i] + 1); // BITの総和 - 自分より左側 ＝ 自分より右側
    //         fw.add(a[i], 1); // 自分の位置に1を足す(ダジャレではないです)
    //     }
    //     cout << ans << endl;
    // }

    //転倒数はrange sumで解ける
    fenwick_tree<ll> fw(N);
    ll ans = 0;
    rep(i, N){
        ans += i - fw.sum(0, a[i] + 1); // BITの総和 - 自分より左側 ＝ 自分より右側
        fw.add(a[i], 1); // 自分の位置に1を足す(ダジャレではないです)
    }
    cout << ans << endl;
    // 一番左の数が一番右に移る時，転倒数は普通に計算できる!
    rep(k, N - 1){
        ans = ans + (N - 1) - 2 * a.at(k);
        cout << ans << endl;
    }
}


int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
