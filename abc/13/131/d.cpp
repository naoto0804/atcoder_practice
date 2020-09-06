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
            return n1.first > n2.first; // 昇順
        }
};

void Main() {
    // 戦略: 〆切が近い方から貪欲に取り出す
    ll N;
    cin >> N;
    priority_queue<P, vector<P>, CompareFirst> q;
    rep(i, N){
        ll a, b;
        cin >> a >> b;
        q.push(make_pair(b, a)); // (〆切, 所要時間)
    }
    bool flag = true;
    ll time = 0;
    while (q.size() > 0){
        auto p = q.top();
        q.pop();
        if (time + p.second > p.first){
            flag = false;
            break;
        } else {
            time += p.second;
        }
        // cout << p.first << " " << p.second << endl;
    }
    if (flag) {cout << "Yes" << endl;} else {cout << "No" << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
