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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> S(M);
    vector<int> p(M);
    rep(i, M){
        int k; cin >> k;
        rep(j, k){
            int s;
            cin >> s;
            s--;
            S.at(i).push_back(s);
        }
    }
    rep(i, M){cin >> p.at(i);}

    int cnt = 0;
    for (int bit = 0; bit < (1<<N); ++bit) { // 1を左に2回シフトすると100
        set<int> on_switches;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) { // i桁目が1かどうか
                on_switches.insert(i);
            }
        }

        bool flag = true;
        rep(i, M){
            int tmp = 0;
            for (auto s: S.at(i)){
                if (on_switches.find(s) != on_switches.end()){tmp += 1;}
            }
            if (tmp % 2 != p.at(i)){flag = false; break;}
        }
        if (flag){cnt += 1;}
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
