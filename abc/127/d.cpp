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

class CompareFirst{ public:
    bool operator()(P n1, P n2) {
        // return n1.first>n2.first; //>:昇順　pairのfirst同士を比較する
        return n1.first < n2.first; // 降順
    }
};


void Main() {
    ll N, M;
    cin >> N >> M;
    priority_queue< ll, vector<ll>, greater<ll> > A; // 小さい方から取り出し
    rep(i, N){ll a; cin >> a; A.push(a);}

    priority_queue<P, vector<P>, CompareFirst> CB;
    rep(i, M){ll b, c; cin >> b >> c; CB.push(make_pair(c, b));}

    while (CB.size() > 0){
        P p = CB.top();
        CB.pop();
        bool flag = false;
        rep(i, p.second){
            if (p.first > A.top()){
                A.pop();
                A.push(p.first);
            } else {
                flag = true;
                break;
            }
        }
        if (flag){break;}
    }
    ll ans = 0;
    while (A.size() > 0){ans += A.top(); A.pop();}
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
