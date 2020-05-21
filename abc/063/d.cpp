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

ll N, A, B;
vector<ll> h;

ll binary_search(ll l, ll r){
    map<ll, bool> tried;
    tried[l] = false;
    tried[r] = true;

    while (true){
        ll mid = (r + l) / 2;

        vector<ll> tmp(h);
        rep(i, tmp.size()){
            tmp.at(i) -= mid * B;
        }
        ll cnt = 0;
        rep(i, tmp.size()){
            if (tmp.at(i) >= 0){
                cnt += ceil((double)(tmp.at(i)) / (A - B));
            }
        }
        // cout << l << " " << mid << " " << r << " " << cnt << endl;

        if (cnt <= mid){
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

    // while l < r:
    //     mid = l + (r - l) // 2
    //     if arr[mid] == x:
    //         return mid
    //     elif arr[mid] > x:
    //         r = mid
    //     else:
    //         l = mid + 1
    // return -1

void Main() {
    // 出来るor出来ないの単調性に注目すると二分探索で済む
    cin >> N >> A >> B;
    rep(i, N){ll tmp; cin >> tmp; h.push_back(tmp);}
    cout << binary_search(0, 1000000000) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
