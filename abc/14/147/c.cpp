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
    int N; cin >> N;
    vector<vector <P>> X(N);
    rep(i, N){
        int a; cin >> a;
        rep(j, a){
            int x, y; cin >> x >> y;
            x--;
            X.at(i).push_back(make_pair(x, y)); // ind, state
        }
    }

    // bit全探索
    int ans = 0;
    for (int bit = 0; bit < (1<<N); ++bit) { // 1を左に2回シフトすると100
        vector<int> S; // 正直者の集合
        vector<int> state(N); rep(i, N){state.at(i) = 0;} // 1: 正直, 0: 嘘つき
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
                state.at(i) = 1;
            }
        }
        bool flag = false; // 失敗すると立つ
        for (auto s: S){
            for (auto p: X[s]){
                if (state.at(p.first) != p.second){ // 証言が矛盾する場合break
                    flag = true;
                }
                if (flag){break;}
            }
            if (flag){break;}
        }
        if (!flag){
            if (S.size() > ans){ans = S.size();}
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
