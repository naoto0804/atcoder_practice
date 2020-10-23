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

ll N, M, K;

ll binary_search(ll l, ll r, vector<ll> A, vector<ll> B, vector<ll> A_sum, vector<ll> B_sum){
    map<ll, bool> tried;
    tried[l] = true;
    tried[r] = false;

    while (true){
        ll mid = (r + l) / 2;

        bool flag = false;
        rep(i, mid + 1){
            if (i > N || mid - i > M || mid - i < 0){continue;}
            if (A_sum.at(i) + B_sum.at(mid - i) <= K){flag = true; break;}
        }
        // cout << mid << " " << flag << endl;

        if (flag){
            l = mid;
            tried[mid] = true;
        } else {
            r = mid;
            tried[mid] = false;
        }

        // // 一つ前ではだめで，ここではokという変曲点があるはず
        if (tried.find(mid+1) != tried.end() && !tried[mid + 1] && tried[mid]){
            return mid;
        }
        if (tried.find(mid-1) != tried.end() && tried[mid - 1] && !tried[mid]){
            return mid - 1;
        }
    }
}

void Main() {
    cin >> N >> M >> K;
    vector<ll> A, B, A_sum, B_sum;
    A_sum.push_back(0);
    B_sum.push_back(0);

    ll a_sum = 0, b_sum = 0;
    rep(i, N){ll a; cin >> a; a_sum += a; A.push_back(a); A_sum.push_back(a_sum);}
    rep(i, M){ll b; cin >> b; b_sum += b; B.push_back(b); B_sum.push_back(b_sum);}

    cout << binary_search(0, N + M + 1, A, B, A_sum, B_sum) << endl;
}

    // ll a_ind = 0, b_ind = 0, cnt = 0, time = 0;
    // while (true){
    //     if (A.at(a_ind) < B.at(b_ind)){ // Aを読む
    //         if (time + A.at(a_ind) <= K){
    //             time += A.at(a_ind);
    //             a_ind++;
    //             cnt++;
    //         } else {
    //             break;
    //         }
    //     } else {
    //         if (time + B.at(b_ind) <= K){
    //             time += B.at(b_ind);
    //             b_ind++;
    //             cnt++;
    //         } else {
    //             break;
    //         }
    //     }
    // }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
