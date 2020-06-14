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
    // 毎回一から計算するとO(N^2)
    // ただし値が変わる場所はたかだか2園だけ

    ll N_elem = 200000;
    ll N, Q; cin >> N >> Q;
    vector<multiset<ll>> x(N_elem); // x[i]: その園にいる人のレートの集合
    multiset<ll> y; // 最強園児のレートの集合
    vector<ll> A; // 園児iのレート
    vector<ll> B; // 園児iが今どこにいるか

    rep(i, N){ // 初期配置を全てとりあえず受け取る
        ll a, b; // レート，位置
        cin >> a >> b; b--;
        A.push_back(a); B.push_back(b);
        x.at(b).insert(a);
    }
    rep(i, N_elem){
        if (x.at(i).size() > 0){
            auto itr1 = x.at(i).end(); itr1--; y.insert(*itr1);
        }
    }

    rep(i, Q){
        ll c, new_ind; // 園児，新しい園
        cin >> c >> new_ind; c--; new_ind--;
        ll old_ind = B.at(c);

        // 元園関連のレコード更新
        auto itr2 = x.at(old_ind).end(); itr2--; y.erase(*itr2);
        x.at(old_ind).erase(A.at(c)); // 該当園児のレートを削除
        if (x.at(old_ind).size() > 0){ // 一個も残らないとバグる
            auto itr3 = x.at(old_ind).end(); itr3--; y.insert(*itr3);
        }

        // 新園関連のレコード更新
        if (x.at(new_ind).size() > 0){ // 一個もそもそも存在していないとバグる
            auto itr4 = x.at(new_ind).end(); itr4--; y.erase(*itr4);
        }
        x.at(new_ind).insert(A.at(c)); // 該当園児のレートを追加
        auto itr5 = x.at(new_ind).end(); itr5--; y.insert(*itr5);
        B.at(c) = new_ind;

        cout << *y.begin() << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
