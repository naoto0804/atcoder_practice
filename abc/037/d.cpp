// ctrl+shift+b
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


using T = pair<ll, P>;
class CompareFirst{ public:
    bool operator()(T n1, T n2) {
        return n1.first > n2.first; // 降順
    }
};

void Main() {
    // ダイクストラ法同様，priority queを使って値が取り出されていないものの中での最小値から確定させる
    ll H, W; cin >> H >> W;
    ll a[H][W];
    ll count[H][W]; rep(i, H){rep(j, W){ count[i][j] = 1;}}
    priority_queue<T, vector<T>, CompareFirst> q;

    rep(i, H){rep(j, W){
        cin >> a[i][j];
        q.push(make_pair(a[i][j], make_pair(i, j)));
    }}
    while (q.size()){
        T t = q.top();
        ll s = t.first, y = t.second.first, x = t.second.second;
        q.pop();
        rep(i, 4){
            ll new_y = y + dy[i];
            ll new_x = x + dx[i];
            if (0 <= new_y && new_y < H && 0 <= new_x && new_x < W && a[y][x] > a[new_y][new_x]){count[y][x] = (count[y][x] + count[new_y][new_x]) % MOD;}
        }
    }
    ll ans = 0;
    rep(i, H){rep(j, W){ans = (ans + count[i][j]) % MOD;}}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
