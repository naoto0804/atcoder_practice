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
    // 最悪計算量が O(HW(H + W))
    // 先に(i,j)で左右上下を向いた時の値を計算してメモすると，O(HW) * O(1)に落ちる
    int H, W;
    cin >> H >> W;
    bool board[H][W];
    rep(i, H){
        string S;
        cin >> S;
        rep(j, W){
            if (S[j] == '#'){board[i][j] = false;} else {board[i][j] = true;}
        }
    }

    int l2r[H][W], r2l[H][W], t2b[H][W], b2t[H][W];
    rep(i, H){
        int tmp = 0;
        rep(j, W){
            if (j == 0){l2r[i][0] = 0;} else {l2r[i][j] = tmp;}
            if (board[i][j]){tmp += 1;} else {tmp = 0; l2r[i][j] = 0;}
        }
    }
    rep(i, H){
        int tmp = 0;
        rrep(j, W-1, 0){
            if (j == W-1){r2l[i][W-1] = 0;} else {r2l[i][j] = tmp;}
            if (board[i][j]){tmp += 1;} else {tmp = 0; r2l[i][j] = 0;}
        }
    }

    rep(j, W){
        int tmp = 0;
        rep(i, H){
            if (i == 0){t2b[0][j] = 0;} else {t2b[i][j] = tmp;}
            if (board[i][j]){tmp += 1;} else {tmp = 0; t2b[i][j] = 0;}
        }
    }

    rep(j, W){
        int tmp = 0;
        rrep(i, H-1, 0){
            if (i == H-1){b2t[H-1][j] = 0;} else {b2t[i][j] = tmp;}
            if (board[i][j]){tmp += 1;} else {tmp = 0; b2t[i][j] = 0;}
        }
    }

    // rep(i, H){rep(j, W){cout << b2t[i][j] << " ";} cout << endl;}
    // rep(i, H){rep(j, W){cout << t2b[i][j] << " ";} cout << endl;}
    int ans = 0;
    rep(i, H){rep(j, W){
        if (board[i][j]){
            int tmp = l2r[i][j] + r2l[i][j] + t2b[i][j] + b2t[i][j] + 1;
            if (tmp > ans){ans = tmp;}
        }
    }}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
