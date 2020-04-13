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


ll solve(int i, ll N){ // i:桁数, pow(10, i)の位だけに注目してNまでの間に出る1の数をカウント
    ll base = (int)pow(10, i);
    ll ans = (N / (10 * base)) * base;
    ll res = N % (10 * base);
    if (base <= res && res < 2 * base){
        ans += res - base + 1;
    } else if (2 * base <= res){
        ans += base;
    }
    return ans;
}

void Main() {
    ll N;
    cin >> N;
    int L = (int)log10(N) + 1;
    ll ans = 0;
    rep(i, L){ans += solve(i, N);}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
