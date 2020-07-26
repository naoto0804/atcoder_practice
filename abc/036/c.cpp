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

void Main() {
    ll N; cin >> N;
    set<ll> X;
    vector<ll> a(N); rep(i, N){
        cin >> a.at(i);
        if (X.find(a.at(i)) == X.end()){X.insert(a.at(i));}
    }
    vector<ll> Y;
    for (auto a: X){Y.push_back(a);}

    vector<int> indices(Y.size());
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&Y](ll i1, ll i2) {
        return Y[i1] < Y[i2]; // これは昇順
    });

    map<ll, ll> ans;
    rep(i, Y.size()){
        ans[Y.at(i)] = indices.at(i);
    }

    for (auto b: a){
        cout << ans[b] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
