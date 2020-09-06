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
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N){cin >> a.at(i);}

    set<int> ans;
    // 大きい数のほうが制約が多いので，大きい方から
    rrep(i, N, 1){
        int tmp = 2;
        bool flag = true; // あまりゼロ
        // O(N/1 + N/2 + ... + N/N) = O(NlogN)
        while (true){
            int num = i * tmp;
            if (num > N){break;}
            if (ans.find(num) != ans.end()){flag = !flag;}
            tmp += 1;
        }
        if ((flag && a.at(i - 1) == 1) || (!flag && a.at(i - 1) == 0)){ans.insert(i);}
    }
    int M = ans.size();
    cout << M << endl;
    if (M != 0){
        for (auto v: ans){cout << v << " ";}
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
