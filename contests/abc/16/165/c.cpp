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

ll N, M, Q;
ll cnt;
vector<ll> A, B, C, D;

// 重複あり順列(のうち単調増加するもの)の列挙
ll search(vector<ll> in){
    if (in.size() == N){
        ll ans = 0;
        rep(i, Q){
            if ((in.at(B.at(i)) - in.at(A.at(i))) == C.at(i)){ans += D.at(i);}
        }
        return ans;
    } else {
        ll start;
        if (in.size() == 0){
            start = 1;
        } else {
            start = in.at(in.size() - 1);
        }

        ll ans = -INF;
        rep2(i, start, M + 1){
            vector<ll> vec(in);
            vec.push_back(i);
            ll tmp = search(vec);
            if (tmp > ans){ans = tmp;}
        }
        return ans;
    }
}

void Main() {
    // N 個の仕切りと M 個のボールを並び替えた列を考えれば組み合わせはN+MCN通りだけ
    cin >> N >> M >> Q;
    rep(i, Q){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        A.push_back(a); B.push_back(b); C.push_back(c); D.push_back(d);
    }
    vector<ll> base;
    cout << search(base) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
