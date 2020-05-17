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
const ll INF = 5000000000000000000L; // change so that it's slightly larger than (2*10^9)^{2}
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    ll N, K; cin >> N >> K;
    vector<ll> x(N), y(N);
    rep(i, N){cin >> x.at(i) >> y.at(i);}

    vector<ll> x_axis(x), y_axis(y);

    sort(x_axis.begin(), x_axis.end());
    sort(y_axis.begin(), y_axis.end());
    x_axis.erase(unique(x_axis.begin(), x_axis.end()), x_axis.end());
    y_axis.erase(unique(y_axis.begin(), y_axis.end()), y_axis.end());

    ll area = INF;
    ll W = x_axis.size(), H = y_axis.size();
    rep(i, W - 1){
        rep2(j, 1, W){
            rep(k, H - 1){
                rep2(l, 1, H){
                    ll xmin = x_axis.at(i), xmax = x_axis.at(j);
                    ll ymin = y_axis.at(k), ymax = y_axis.at(l);
                    ll cnt = 0;
                    rep(m, N){
                        if (xmin <= x.at(m) && x.at(m) <= xmax && ymin <= y.at(m) && y.at(m) <= ymax){
                            cnt += 1;
                        }
                    }
                    if (cnt >= K){
                        ll tmp_area = (xmax - xmin) * (ymax - ymin);
                        if (tmp_area < area){area = tmp_area;}
                    }
                }
            }
        }
    }
    cout << area << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
