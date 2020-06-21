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

// 素因数分解
map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}

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

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return (a.second < b.second); // 昇順
}

vector<ll> vec;

ll num(ll n){
    ll ans = 0;
    for (auto v: vec){if (v >= n - 1){ans++;}}
    return ans;
}

void Main() {
    ll N; cin >> N;
    map<ll, ll> x; // 素因数分解
    rep2(i, 1, N + 1){
        map<ll, ll> tmp = prime_factorize(i);
        for (auto a: tmp){
            if (x.find(a.first) != x.end()){
                x[a.first] += a.second;
            } else {
                x[a.first] = a.second;
            }
        }
    }
    for (auto a: x){vec.push_back(a.second);}
    sort(vec.begin(), vec.end(), greater<ll>());

    // 6 = 2^{1} * 3^{1} だと (1 + 1) * (1 + 1) 個の約数
    // 75個約数があるには
    // (74 + 1)
    // (24 + 1, 2 + 1), (14 + 1, 4 + 1)
    // (4 + 1, 4 + 1, 2 + 1)
    // のどれか

    ll ans = 0;
    ans += num(75);
    ans += num(25) * (num(3) - 1); // 大きい方から取っていくと分かりやすい
    ans += num(15) * (num(5) - 1);
    ans += num(5) * (num(5) - 1) * (num(3) - 2) / 2;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
