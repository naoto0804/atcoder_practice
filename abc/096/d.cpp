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

// 素数列挙
vector<int> prime_list(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> res;
    int i = 2;
    while (pow(i, 2) <= n) {
        if (is_prime[i]) {
            int j = i + i;
            while (j <= n) {
                is_prime[j] = false;
                j += i;
            }
        }
        i++;
    }
    for (int i = 0; i <= n; ++i) {
        if (is_prime[i] && i >= 2) {
            res.push_back(i);
        }
    }
    return res;
}

void Main() {
    ll N; cin >> N;
    vector<ll> x;
    for (auto a: prime_list(55555)){
        // cout << a << endl;
        if (a % 5 == 1){x.push_back(a);}
        if (x.size() >= N){break;}
    }
    for (auto a: x){cout << a << " ";}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
