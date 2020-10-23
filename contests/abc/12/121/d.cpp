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

ll func(ll n){
    if (n % 2 == 1){
        return ((n + 1) / 2) % 2;
    }else{
        return ((n / 2) % 2) ^ n;
    }
}

void Main() {
    // x ^ y: xとyの排他的論理和
    // F(A, B) = F(0, A-1) ^ F(0,B) なので，まずF(0,n)を求める
    // 任意の偶数に対して n ^ n+1 = 1
    // 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6
    // = 1 ^ 1 ^ 1 ^ 6
    ll A, B; cin >> A >> B;
    cout << (func(B) ^ func(A-1)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
