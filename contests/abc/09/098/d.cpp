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
    /* 入力受け取り */
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N){cin >> A[i];}

    int sum = 0;
    ll res = 0;
    int right = 0;
    rep(left, N){
        while (right < N && ((sum ^ A[right]) == (sum + A[right]))){
            sum += A[right];
            ++right;
        }
        res += (right - left);
        if (left == right) { // when left == right == 0
            ++right;
        } else {
            sum -= A[left];
        }
    }
    cout << res << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
