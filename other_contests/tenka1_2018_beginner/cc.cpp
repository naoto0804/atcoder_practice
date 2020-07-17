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

ll solve(vector<ll> A){
    ll N = A.size();
    ll ans = 0;
    ll left_ind = 0, right_ind = N - 2;
    ll left = A.at(N - 1), right = A.at(N - 1);
    bool from_left = true;

    while (left_ind <= right_ind){
        if (from_left){
            if (right_ind - left_ind >= 1){
                ans += abs(A.at(left_ind) - left); left = A.at(left_ind);
                ans += abs(A.at(left_ind + 1) - right); right = A.at(left_ind + 1);
                left_ind += 2;
            } else {
                ans += max(abs(A.at(left_ind) - left), abs(A.at(left_ind) - right));
                left_ind += 1;
            }
        } else {
            if (right_ind - left_ind >= 1){
                ans += abs(A.at(right_ind) - left); left = A.at(right_ind);
                ans += abs(A.at(right_ind - 1) - right); right = A.at(right_ind - 1);
                right_ind -= 2;
            } else {
                ans += max(abs(A.at(right_ind) - left), abs(A.at(right_ind) - right));
                right_ind -= 1;
            }
        }
        from_left = !from_left;
    }
    return ans;
}

void Main() {
    // 左/右端の値を中心に成長させる場合で値が違ってくるので注意
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i, N){cin >> A.at(i);}

    sort(A.begin(), A.end());
    ll ans1 = solve(A);
    sort(A.begin(), A.end(), greater<ll>());
    ll ans2 = solve(A);

    cout << max(ans1, ans2) << endl;

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
