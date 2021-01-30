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

// 約数列挙
vector<ll> divisor(ll N) {
    vector<ll> res;
    for (ll i = 1L; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            ll j = N / i;
            if (j != i)  {
                res.push_back(j);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void Main() {
    ll N; cin >> N;
    // aからbまでの等差数列の和をXとすると，X=(a+b)*(b-a+1)/2
    // 2Xを因数分解した時にこれを満たすかひたすら考えれば良い

    vector<ll> x = divisor(2 * N);
    ll ans = 0;
    for (ll d1 : x){
        if (d1 < sqrt(2 * N)){continue;}
        ll d2 = 2 * N / d1;
        double b = (d1 + d2 - 1) / 2.0;
        double a = (d1 - d2 + 1) / 2.0;
        // cout << d1 << " " << d2 << endl;

        if (((double)(ll)a == a) && ((double)(ll)b == b)){
            // cout << a << " " << b << endl;
            ans += 1;
        }
    }
    cout << ans * 2 << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
