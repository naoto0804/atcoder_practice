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

class CompareFirst{ public:
    bool operator()(P n1, P n2) {
        return n1.first > n2.first; //>:昇順　pairのfirst同士を比較する
        // return n1.first < n2.first; // 降順
    }
};

void Main() {
    ll N; cin >> N;

    // 拡張priority queue (llを２つ格納，１つ目でソート)
    priority_queue<P, vector<P>, CompareFirst> cd; // blue側はxの小さい方から取り出す
    set<P> ab;
    rep(i, N){ll a, b; cin >> a >> b; ab.insert(make_pair(a, b));}
    rep(i, N){ll c, d; cin >> c >> d; cd.push(make_pair(c, d));}

    // ただの貪欲探索
    // 青のx座標が最も小さいものと，ペアになれるもののうち最もy座標が大きいものとペアにする
    ll cnt = 0;
    while(cd.size() > 0){
        P q = cd.top(); cd.pop();
        ll tmp_y = -INF; P tmp_P;
        for (P a: ab){
            if (a.first < q.first && a.second < q.second && a.second > tmp_y){tmp_y = a.second; tmp_P = a;}
        }
        if (tmp_y > -INF){cnt++; ab.erase(tmp_P);}
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
