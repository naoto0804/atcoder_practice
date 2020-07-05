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
    ll N, K; cin >> N >> K;
    vector<ll> plus, minus;
    ll zero_cnt = 0;
    rep(i, N){
        ll a; cin >> a;
        if (a >= 0){
            plus.push_back(a);
        } else if (a < 0){
            minus.push_back(a);
        }
    }
    sort(plus.begin(), plus.end(), greater<ll>());  // 大きい方から
    sort(minus.begin(), minus.end());  // 小さい方から

    ll p_size = plus.size();
    ll m_size = minus.size();

    ll ans = 1;
    if (plus.size() == 0){ // オールマイナス
        if (K % 2 == 1){
            rep(i, K){
                ans *= minus.at(N - 1 - i);
                ans %= MOD;
            }
        } else {
            rep(i, K){
                ans *= minus.at(i);
                ans %= MOD;
            }
        }
    } else {
        ll p_ind = 0, m_ind = 0, cnt = 0;
        if (K % 2 == 1){p_ind++; ans *= plus.at(0); ans %= MOD; cnt++;}
        while (cnt < K){
            // cout << p_ind << " " << m_ind << endl;
            if (p_size - p_ind >= 2 && m_size - m_ind >= 2){
                ll p_cand = plus.at(p_ind) * plus.at(p_ind + 1);
                ll m_cand = minus.at(m_ind) * minus.at(m_ind + 1);
                if (p_cand >= m_cand){
                    p_ind += 2; ans *= p_cand; ans %= MOD; cnt += 2;
                } else {
                    m_ind += 2; ans *= m_cand; ans %= MOD; cnt += 2;
                }
            } else if (p_size - p_ind >= 2){
                ans *= plus.at(p_ind);
                ans %= MOD;
                ans *= plus.at(p_ind + 1);
                ans %= MOD;
                p_ind += 2; cnt += 2;
            } else if (m_size - m_ind >= 2){
                ans *= minus.at(m_ind);
                ans %= MOD;
                ans *= minus.at(m_ind + 1);
                ans %= MOD;
                m_ind += 2; cnt += 2;
            } else {
                ans *= minus.at(m_ind);
                ans %= MOD;
                ans *= plus.at(p_ind);
                ans %= MOD;
                m_ind++; p_ind++; cnt += 2;
            }
        }
    }
    if (ans < 0){ans += MOD;}
    cout << ans << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
