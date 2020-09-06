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
    ll n; cin >> n;
    vector<ll> odd, even, ans;
    rep(i, n){
        ll tmp;
        cin >> tmp;
        if (i % 2 == 0){
            even.push_back(tmp);
        } else {
            odd.push_back(tmp);
        }
    }

    // n が奇数: 奇数番目の反転 -> 偶数番目
    // n が偶数: 偶数番目の反転 -> 奇数番目
    if (n % 2 == 1){
        reverse(even.begin(), even.end());
        ans = even;
        ans.insert(ans.end(), odd.begin(), odd.end());
    } else {
        reverse(odd.begin(), odd.end());
        ans = odd;
        ans.insert(ans.end(), even.begin(), even.end());
    }
    for (auto a: ans){cout << a << " ";}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
