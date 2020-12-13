// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll> >;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
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

int op(int a, int b) {
    return a ^ b;
}

int e() {
    return (int)(1e9);
}

void Main() {
    int N, Q; cin >> N >> Q;

    // 各range queryをlogNで処理できれば全体の計算時間は最悪でもNlogNなので間に合う -> セグ木
    segtree<int, op, e> seg(N);
    rep(i, N){
        int a; cin >> a;
        seg.set(i, a);
    }
    rep(i, Q){
        int t, x, y; cin >> t >> x >> y;
        if (t == 1){
            x--;
            seg.set(x, seg.get(x) ^ y);
        } else {
            x--; y--;
            if (x == y){
                cout << seg.get(x) << endl;
            } else {
                cout << seg.prod(x, y + 1) << endl;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
