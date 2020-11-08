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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 998244353;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

bool op(bool cur, bool is_lamp, bool is_block){
    bool ans = cur;
    if (is_lamp){ans = true;}
    if (is_block){ans = false;}
    return ans;
}

void Main() {
    // 各光からの到達を貪欲に追うのは時間がかかるが，4方向に(現在明かりが走査方向に届いているか)のflagを持って走査するのはO(HW)
    ll H, W, N, M; cin >> H >> W >> N >> M;
    bool is_block[H][W]; rep(i, H){rep(j, W){is_block[i][j] = false;}}
    bool is_lamp[H][W], ans[H][W]; rep(i, H){rep(j, W){is_lamp[i][j] = false; ans[i][j] = false;}}
    rep(i, N){ll a, b; cin >> a >> b; is_lamp[a - 1][b - 1] = true;}
    rep(i, M){ll c, d; cin >> c >> d; is_block[c - 1][d - 1] = true;}

    rep(i, H){bool tmp = false; rep(j, W){tmp = op(tmp, is_lamp[i][j], is_block[i][j]); if (tmp){ans[i][j] = true;}}} // left2right
    rep(i, H){bool tmp = false; rrep(j, W - 1, 0){tmp = op(tmp, is_lamp[i][j], is_block[i][j]); if (tmp){ans[i][j] = true;}}} // right2left
    rep(j, W){bool tmp = false; rep(i, H){tmp = op(tmp, is_lamp[i][j], is_block[i][j]); if (tmp){ans[i][j] = true;}}} // top2bottom
    rep(j, W){bool tmp = false; rrep(i, H - 1, 0){tmp = op(tmp, is_lamp[i][j], is_block[i][j]); if (tmp){ans[i][j] = true;}}} // bottom2top
    ll cnt = 0;
    rep(i, H){rep(j, W){if (ans[i][j]){cnt++;}}}
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
