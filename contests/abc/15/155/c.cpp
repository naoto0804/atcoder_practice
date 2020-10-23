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
    map<string, int> cnt;
    rep(i, N){
        string s;
        cin >> s;
        if (cnt.find(s) != cnt.end()){cnt[s] += 1;} else {cnt[s] = 0;}
    }
    int max_cnt = 0;
    vector<string> words;
    for (auto it : cnt) {
        if (max_cnt < it.second){
            max_cnt = it.second;
            words.clear();
            words.push_back(it.first);
        } else if (max_cnt == it.second){
            words.push_back(it.first);
        }
    }
    sort(words.begin(), words.end());
    for (auto it : words) {cout << it << endl; }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
