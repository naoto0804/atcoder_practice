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
    ll N, K; cin >> N >> K;
    vector<ll> A(N); rep(i, N){ll tmp; cin >> tmp; A.at(i) = tmp - 1;}

    vector<ll> history; // n回目の場所を逐一記録 (0-index)
    map<ll, ll> visited; // 何回目に通った街か？が大事
    history.push_back(0);
    visited[0] = 0;

    ll cnt = 1;
    ll prev = 0;
    ll loop_size;
    vector<ll> loop_array;

    while (true){
        ll next = A.at(prev);
        history.push_back(next);

        if (visited.find(next) != visited.end()){
            loop_size = cnt - visited[next];
            for(ll i=0; i < (ll)(loop_size); i++){
                loop_array.push_back(history.at(visited[next] + i));
            }
            break;
        } else {
            visited[next] = cnt;
        }
        prev = next;
        cnt++;
    }

    if (K <= cnt){ // ループ検出前
        cout << history.at(K) + 1 << endl;
    } else { // ループ検出後
        ll tmp = (K - cnt) % loop_size;
        cout << loop_array.at(tmp) + 1 << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
