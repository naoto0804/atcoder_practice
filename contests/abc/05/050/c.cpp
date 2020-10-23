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

ll pow(ll x, ll y, ll mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return pow(x * x % mod, y / 2, mod) % mod;
    } else {
        return x * pow(x, y - 1, mod) % mod;
    }
}

void Main() {
    ll N; cin >> N;
    map<ll, ll> A;
    rep(i, N){
        ll tmp;
        cin >> tmp;
        if (A.find(tmp) != A.end()){
            A[tmp]++;
        } else {
            A[tmp] = 1;
        }
    }
    bool flag = true;
    for (auto a: A){
        if (a.first == 0){
            if (N % 2 == 0){
                flag = false; break;
            } else {
                if (a.second != 1){flag = false; break;}
            }
        } else {
            if (a.second != 2){flag = false; break;}
        }
    }
    ll ans = flag ? pow(2, N / 2, MOD) : 0;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
