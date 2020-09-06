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

// void Main() {
//     ll N; cin >> N;
//     vector<ll> A(N); rep(i, N){cin >> A.at(i);}
//     ll cnt = 0;
//     rep(i, N){
//         vector<ll> res = divisor(A.at(i)); // 約数群
//         bool flag = true;
//         rep(j, N){
//             if (i == j){continue;}
//             if (binary_search(res.begin(), res.end(), A.at(j))){
//                 flag = false; break;
//             };
//         }
//         if (flag){cnt++;}
//     }
//     cout << cnt << endl;
// }


void Main() {
    // ナイーブ解はN^2logN
    // 約数に関してloopして辞書検索することでNlogN
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N){cin >> A.at(i);}
    // set<ll> Aset(A.begin(), A.end());,
    map<ll, ll> m;
    for (auto a: A){
        if (m.find(a) != m.end()){m[a]++;}else{m[a] = 1;}
    }

    ll cnt = 0;
    rep(i, N){
        vector<ll> res = divisor(A.at(i)); // 約数群
        bool flag = true;
        rep(j, res.size()){
            ll num = res.at(j);
            if (j == res.size() - 1){
                if (m.find(num) != m.end() && m[num] > 1){flag = false;}
            } else {
                if (m.find(num) != m.end()){flag = false;}
            }
        }
        if (flag){cnt++;}
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
