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
    // 重みの範囲が制限されているタイプのナップザック -> 重みで場合分け
    ll N, W; cin >> N >> W;

    ll w1, v1; cin >> w1 >> v1;

    // 重みは 0, 1, 2, 3 (各入力からw1を引く)
    map<ll, vector<ll>> x;
    map<ll, vector<ll>> acc_y; // 重みwをn個使ったときの累積和
    x[0].push_back(v1);

    rep(i, N - 1){
        ll tmp_w, tmp_v;
        cin >> tmp_w >> tmp_v;
        x[tmp_w - w1].push_back(tmp_v);
    }
    rep(i, 4){
        acc_y[i].push_back(0);
        if (x[i].size() > 0){
            // 同じ重みの中では価値が高い方から優先的に使うためソート
            sort(x[i].begin(), x[i].end(), greater<ll>());
            ll tmp = 0;
            rep(j, x[i].size()){
                tmp += x[i].at(j);
                acc_y[i].push_back(tmp);
            }
        }
    }

    ll max_value = -INF;
    // 何個使うかは4重ループで強引に列挙，maxで(N/4)^4の計算量なのでN=100なら間に合う
    rep(i, x[0].size() + 1){
        rep(j, x[1].size() + 1){
            rep(k, x[2].size() + 1){
                rep(l, x[3].size() + 1){
                    ll weight = w1 * (i + j + k + l) + j + 2 * k + 3 * l;
                    ll value = (acc_y[0].at(i) - acc_y[0].at(0));
                    value += (acc_y[1].at(j) - acc_y[1].at(0));
                    value += (acc_y[2].at(k) - acc_y[2].at(0));
                    value += (acc_y[3].at(l) - acc_y[3].at(0));
                    // cout << i << " " << j << " " << k << " " << l << " " << weight << " " << value << endl;
                    if (weight <= W && value > max_value){max_value = value;}
                }
            }
        }
    }
    cout << max_value << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
