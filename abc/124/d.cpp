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

vector<pair<char, ll>> RLE(const string &S) {
    ll cnt = 0;
    vector<pair<char, ll>> res;
    for (ll i = 0; i < (ll) S.size(); i++) {
        cnt++;
        if (i == (ll) S.size() - 1) {
            res.emplace_back(S[i], cnt);
            break;
        }
        if (S[i] != S[i + 1]) {
            res.emplace_back(S[i], cnt);
            cnt = 0;
        }
    }
    return res;
}

void Main() {
    // 考察
    // S1=0の時2K-1箇所潰す
    // S1=1の時2K箇所潰す

    ll N, K; cin >> N >> K;
    string S; cin >> S;

    int max_len = 1;
    int last = N-1, num_zero = (S.back() == '0');
    for(int first = N-2; 0 <= first; first--){
        if(S[first] == '1'|| (S[first] == '0' && S[first+1] == '0')) {
            max_len = max(max_len,last - first +1);
        } else {
            ++num_zero;
            while(K < num_zero) {
                while (S[last]=='1')--last;
                while (S[last]=='0')--last;
                --num_zero;
            }
            max_len = max(max_len,last - first +1);
        }
    }
    cout << max_len << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
