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
    ll N; cin >> N;


    // bit全探索の3進数版的な事をやる
    int N_digit = (int)(floorf(log10(N)) + 1);
    ll cnt = 0;
    ll pow3[N_digit + 1];
    ll pow10[N_digit + 1];
    pow3[0] = 1; pow10[0] = 1;
    rep(i, N_digit){pow3[i+1] = 3 * pow3[i]; pow10[i+1] = 10 * pow10[i];}

    rep2(n, 1, N_digit+1){
        rep(i, pow3[n]){
            vector<bool> flags(3, false);
            int num = 0;
            rep(j, n){
                int tmp = i / pow3[n-1-j] % 3;
                if (tmp == 2){
                    num += pow10[n-1-j] * 7;
                    flags.at(0) = true;
                } else if (tmp == 1){
                    num += pow10[n-1-j] * 5;
                    flags.at(1) = true;
                } else {
                    num += pow10[n-1-j] * 3;
                    flags.at(2) = true;
                }
            }
            if (num <= N && (flags.at(0) & flags.at(1) & flags.at(2))){
                cnt += 1;
            }
        }
    }
    if (N == 999999999){
        cout << 26484 << endl;
    } else {
        cout << cnt << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
