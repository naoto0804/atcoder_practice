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
    // aのmaxより大きいbを使い切ってから，aのmaxを繰り返す
    // というふうにすると，実は順番の前後(どの刀を手に取るか / 振るかor投げるか)がどうでも良くなる -> 貪欲に戦略を立てる
    ll N, H; cin >> N >> H;
    vector<ll> a(N), b(N);
    rep(i, N){cin >> a.at(i) >> b.at(i);}
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());

    ll amax = a.at(0);
    ll ind = 0;
    ll cost = 0;
    while (true){
        if (cost < H && ind < b.size() && b.at(ind) > a.at(0)){
            cost += b.at(ind);
            ind++;
        } else {
            break;
        }
    }
    if (cost >= H){
        cout << ind << endl;
    } else {
        cout << ind + (ll)(ceil((H - cost) / (double)(a.at(0)))) << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
