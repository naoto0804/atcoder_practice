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
    ll A, B, H, M; cin >> A >> B >> H >> M;
    double h = 0.5 * M_PI - 2 * M_PI * (H + M / (double)60) / (double)12;
    double h_x = A * cos(h);
    double h_y = A * sin(h);

    double m = 0.5 * M_PI - 2 * M_PI * M / (double)60;
    double m_x = B * cos(m);
    double m_y = B * sin(m);

    cout << sqrt((m_x - h_x) * (m_x - h_x) + (m_y - h_y) * (m_y - h_y)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
