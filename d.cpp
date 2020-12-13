// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll> >;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[3] = {-1, 0, -1};
const int dy[3] = {0, -1, -1};
// const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

/**
 * ランレングス圧縮
 */
vector<pair<char, ll>> RLE(const string &S) {
    ll cnt = 0;
    vector<pair<char, ll>> res;
    for (ll i = 0; i < (ll) S.size(); i++) {
        cnt++;
        if (i == (ll) S.size() - 1) {
            res.emplace_back(S[i], cnt);
            break;
        }
        if (S[i] != S[i + 1]) {
            res.emplace_back(S[i], cnt);
            cnt = 0;
        }
    }
    return res;
}

void Main() {
    int N, M; cin >> N >> M;
    ll start = 0;
    vector<ll> A;
    rep(i, M){ll tmp; cin >> tmp; A.push_back(tmp);}
    A.push_back(0);
    A.push_back(N + 1);
    sort(A.begin(), A.end()); // 昇順 ascending

    vector<ll> res;
    for (auto a: A){
        if (a - start > 1){res.push_back(a - start - 1);}
        start = a;
    }
    if (res.size() > 0){
        ll k = *min_element(res.begin(), res.end());
        ll ans = 0;
        for (auto a: res){
            cout << a << " " << k << " " << ceil((float) a / k) << endl;
            ans += ceil((float) a / k);
        }
        cout << ans << endl;
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
