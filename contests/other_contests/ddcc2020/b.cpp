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
    vector<ll> A(N), total_A(N + 1); total_A.at(0) = 0;
    rep(i, N){cin >> A.at(i); total_A.at(i + 1) += (A.at(i) + total_A.at(i));}
    ll L = total_A.at(N);
    if (L % 2 == 0 && find(total_A.begin(), total_A.end(), L / 2) != total_A.end()){
        cout << 0 << endl;
    } else {
        rep(i, N){
            if (total_A.at(i) < L / 2 && total_A.at(i + 1) > L / 2){
                // cout << total_A.at(i) << " " << total_A.at(i + 1) << " " << L << endl;
                // cout << abs(total_A.at(i) - (L - total_A.at(i))) << endl;
                // cout << abs(total_A.at(i + 1) - (L - total_A.at(i + 1))) << endl;
                cout << min(abs(total_A.at(i) - (L - total_A.at(i))), abs(total_A.at(i + 1) - (L - total_A.at(i + 1)))) << endl;
                exit(0);
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
