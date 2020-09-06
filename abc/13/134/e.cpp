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
    ll N; cin >> N; vector<ll> A(N); rep(i, N){cin >> A.at(i);}
    // やり方
    // (i) ((1, 4), (2), (0)) みたいに単調増加する数列の入れ物を持つ, 最大値だけ簡単に取り出せるようにしておくことが大事
    // - どの最大値よりも低いものが来た場合は，新しい組が生成
    // - そうじゃない場合は，ぎりぎり大きいものを使う (上の例では，3が来たら(0)側ではなく(2)側に)
    // あ，完全に二分探索やん,,

    vector<ll> x; // これは必ずソートされている前提
    rep(i, N){
        if (x.size() == 0){
            x.push_back(A.at(i));
        } else {
            if (A.at(i) <= x.at(0)){
                // 最小なので先頭に入れる
                x.insert(x.begin(), A.at(i));
            } else {
                // 二分探索で座標を得て入れ替え
                // (2, 4) に3を入れるなら 2 -> 3
                auto pos = lower_bound(x.begin(), x.end(), A.at(i));
                x[distance(x.begin(), pos) - 1] = A.at(i);
            }
        }
    }
    cout << x.size() << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
