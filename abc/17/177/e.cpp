// ctrl+shift+b
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
set<ll> prime_factorize(ll N) {
    set<ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            if (res.find(i) == res.end()){res.insert(i);}
            N /= i;
        }
    }
    if (N != 1 && res.find(N) == res.end()){res.insert(N);}
    return res;
}

void Main() {
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N){cin >> A.at(i);}

    set<ll> res = prime_factorize(A.at(0));
    set<ll> pw_set = res;
    set<ll> sw_set = res;

    bool is_pw = true, is_sw = true;
    rep(i, N - 1){
        ll a = A.at(i + 1);
        set<ll> res = prime_factorize(a);
        set<ll> tmp;
        for (auto r: res){
            if (pw_set.find(r) == pw_set.end()){
                pw_set.insert(r);
            } else {
                is_pw = false;
            }
            if (sw_set.find(r) != sw_set.end()){tmp.insert(r);}
        }
        sw_set = tmp;
    }
    if (is_pw){
        cout << "pairwise coprime" << endl;
    } else if (sw_set.size() == 0){
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
