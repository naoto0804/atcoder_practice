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

ll pow(ll x, ll y, ll mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return pow(x * x % mod, y / 2, mod) % mod;
    } else {
        return x * pow(x, y - 1, mod) % mod;
    }
}

ll calc_cost(vector<ll> vec, ll target){
    ll sum_vec = accumulate(vec.begin(), vec.end(), 0);
    ll cost = 10 * (vec.size() - 1);
    cost += abs(target - sum_vec);
    return cost;
}

void Main() {
    // 考察: 順番は変えられる，合成->(加算or減算)でいい
    // 木の本数が少ないので(どれにも使わない, A, B, C)用の木のプールを用意して全ての組み合わせを探索
    ll N, A, B, C; cin >> N >> A >> B >> C;
    vector<ll> l(N); rep(i, N){cin >> l.at(i);}
    ll best_cost = INF;

    // bit全探索の4乗ver.
    rep(i, pow(4, N, MOD)){
        ll cost = 0;
        vector<ll> vec1, vec2, vec3;
        rep(j, N){
            switch (i / pow(4, j, MOD) % 4){
                case 0: break; // do nothing
                case 1: vec1.push_back(l.at(j)); break;
                case 2: vec2.push_back(l.at(j)); break;
                case 3: vec3.push_back(l.at(j)); break;
            }
        }

        // 一本も木が入らないパターンを排除
        if (vec1.size() == 0 || vec2.size() == 0 || vec3.size() == 0){continue;}
        cost += calc_cost(vec1, A);
        cost += calc_cost(vec2, B);
        cost += calc_cost(vec3, C);
        if (cost < best_cost){best_cost = cost;}
    }
    cout << best_cost << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
