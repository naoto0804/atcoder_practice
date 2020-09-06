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
    string S, ans; cin >> S;
    // cout << stoi(S.substr(0, 2)) << endl;
    bool flag1 = false, flag2 = false; // YY formatが確定な時
    int i1 = stoi(S.substr(0, 2)), i2 = stoi(S.substr(2, 2));
    if (i1 >= 13 || i1 <= 0){flag1 = true;}
    if (i2 >= 13 || i2 <= 0){flag2 = true;}
    if (flag1 && flag2){
        cout << "NA" << endl;
    } else if (flag1 && !flag2){
        cout << "YYMM" << endl;
    } else if (!flag1 && flag2){
        cout << "MMYY" << endl;
    } else {
        cout << "AMBIGUOUS" << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
