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

//　タプルのソート
using T = tuple<ll, ll, ll>;
class CompareFirst{ public:
    bool operator()(T n1, T n2) {
        return get<0>(n1) < get<0>(n2);  // 降順
    }
};

void Main() {
    ll N; cin >> N;
    vector<ll> A(N); rep(i, N){cin >> A.at(i);}
    sort(A.begin(), A.end(), greater<ll>());  // 大きい方から取り出す
    // (score(=smaller), larger, smaller) の組を更新

    priority_queue<T, vector<T>, CompareFirst> q;
    q.push(make_tuple(A.at(1), A.at(0), A.at(1)));
    q.push(make_tuple(A.at(1), A.at(0), A.at(1)));
    ll ans = A.at(0);

    rep(i, N - 2){
        T t = q.top();
        q.pop();
        q.push(make_tuple(A.at(i + 2), get<1>(t), A.at(i + 2)));
        q.push(make_tuple(A.at(i + 2), get<2>(t), A.at(i + 2)));
        ans += get<0>(t);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
