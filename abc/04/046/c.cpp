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

vector<ll> binary_search(ll l, ll r, ll num1, ll num2, ll t, ll a){
    // tx >= num1, ax >= num2 となる最小のxを見つける
    vector<ll> ans;
    map<ll, bool> tried;
    tried[l] = false;
    tried[r] = true;

    while (true){
        ll mid = (r + l) / 2;

        // 後半２つは t*midやa*midがoverflowしないための例外処理
        bool cond = (t * mid >= num1 && a * mid >= num2 || INF / mid <= t || INF / mid <= a);
        if (cond){
            r = mid;
            tried[mid] = true;
        } else {
            l = mid;
            tried[mid] = false;
        }

        // 一つ前ではだめで，ここではokという変曲点があるはず
        if (tried.find(mid+1) != tried.end() && tried[mid + 1] && !tried[mid]){
            ans.push_back(t * (mid + 1)); ans.push_back(a * (mid + 1));
            return ans;
        }
        if (tried.find(mid-1) != tried.end() && !tried[mid - 1] && tried[mid]){
            ans.push_back(t * mid); ans.push_back(a * mid);
            return ans;
        }
    }
}


void Main() {
    ll t, a, N; cin >> N;
    ll num1 = 1, num2 = 1;
    rep(i, N){
        cin >> t >> a;
        vector<ll> ans = binary_search(0, 1000000000000000000, num1, num2, t, a);
        num1 = ans.at(0); num2 = ans.at(1);
    }
    cout << num1 + num2 << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
