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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void Main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> R, G;
    set<int> B;
    rep(i, N){
        if (S[i] == 'R'){R.push_back(i);}
        if (S[i] == 'G'){G.push_back(i);}
        if (S[i] == 'B'){B.insert(i);}
    }
    ll ans = R.size() * G.size() * B.size();
    for (auto r : R){for (auto g : G){
        if ( (r + g) % 2 == 0){
            int k = (r + g) / 2;
            if (B.find(k) != B.end()){ans -= 1;}
        }
        if (0 <= (2 * g - r) < N){
            if (B.find(2 * g - r) != B.end()){ans -= 1;}
        }
        if (0 <= (2 * r - g) < N){
            if (B.find(2 * r - g) != B.end()){ans -= 1;}
        }
    }}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
