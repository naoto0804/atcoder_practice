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
    ll N, N_digit = 1; cin >> N;
    ll K = 26;

    vector<ll> pow_tmp, sum_tmp;
    pow_tmp.push_back(1); sum_tmp.push_back(0);
    while (true){
        pow_tmp.push_back(pow_tmp.back() * K);
        sum_tmp.push_back(sum_tmp.back() + pow_tmp.back());
        ll size = sum_tmp.size();
        if (sum_tmp.at(size - 2) < N && N <= sum_tmp.at(size - 1)){
            N -= sum_tmp.at(size - 2);
            break;
        }
        if (sum_tmp.back() > 1000000000000001){break;}
        N_digit++;
    }

    N--;
    vector<ll> x;
    rep(i, N_digit){
        x.push_back(N % K);
        N = N / K;
    }
    reverse(x.begin(), x.end());
    for (auto a: x){
        cout << (char) ('a' + a);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
