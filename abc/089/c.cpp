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

vector<ll> cnt(5, 0);
ll ans = 0;

// 組み合わせを全探索し，使われるindexの集合を返す
void search(ll n, ll k, vector<ll> v){
    if (v.size() == k){
        ll tmp = 1;
        for (auto a: v){
            tmp *= cnt[a];
        }
        ans += tmp;
    } else {
        ll start = (v.size() > 0) ? v.at(v.size() - 1) + 1 : 0; // 重複はNGなので+1
        rep2(i, start, n){
            vector<ll> new_v(v);
            new_v.push_back(i);
            search(n, k, new_v);
        }
    }
}

void Main() {
    ll N; cin >> N;
    rep(i, N){
        string s; cin >> s;
        if (s[0] == 'M'){cnt.at(0) += 1;}
        else if (s[0] == 'A'){cnt.at(1) += 1;}
        else if (s[0] == 'R'){cnt.at(2) += 1;}
        else if (s[0] == 'C'){cnt.at(3) += 1;}
        else if (s[0] == 'H'){cnt.at(4) += 1;}
    }
    vector<ll> v(0);
    search(5, 3, v);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
