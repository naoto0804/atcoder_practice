// ctrl+shift+b
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

ll N, K;
vector<ll> A;


ll binary_search(ll l, ll r){
    map<ll, bool> tried;
    tried[l] = false;
    tried[r] = true;

    while (true){
        ll mid = (r + l) / 2; // 最も長い丸太

        ll k_sum = 0;
        for (auto a: A){
            // 許容長さ3だとして，6/3 なら1回だが7/3なら2回切る必要が..
            k_sum += ((ll) ceil((double) a / mid) - 1);
        }

        if (k_sum <= K){
            r = mid;
            tried[mid] = true;
        } else {
            l = mid;
            tried[mid] = false;
        }

        // 一つ前ではだめで，ここではokという変曲点があるはず
        if (tried.find(mid+1) != tried.end() && tried[mid + 1] && !tried[mid]){
            return mid + 1;
        }
        if (tried.find(mid-1) != tried.end() && !tried[mid - 1] && tried[mid]){
            return mid;
        }
    }
}

void Main() {
    // 状態数的にDPではなさそう
    // 最小の長さに関して二分探索
    cin >> N >> K;
    rep(i, N){ll a; cin >> a; A.push_back(a);}
    sort(A.begin(), A.end());
    if (K == 0){
        cout << A.at(A.size() - 1) << endl;
    } else {
        cout << binary_search(0, 1000000001) << endl; // 境界は答えの値を含まないように!!!! (10分溶かした)
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
