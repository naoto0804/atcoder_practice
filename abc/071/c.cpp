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
    ll N; cin >> N;
    vector<ll> A;
    map<ll, ll> x;
    rep(i, N){
        ll tmp;
        cin >> tmp;
        if (x.find(tmp) != x.end()){
            x[tmp] += 1;
        } else {
            x[tmp] = 1;
            A.push_back(tmp);
        }
    }
    sort(A.begin(), A.end(), greater<ll>());

    vector<ll> ans;
    for (auto a: A){
        if (ans.size() >= 2){break;}
        if (x[a] >= 4){ans.push_back(a); ans.push_back(a); break;}
        if (x[a] >= 2){ans.push_back(a);}
    }
    if (ans.size() >= 2){
        cout << ans.at(0) * ans.at(1) << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
