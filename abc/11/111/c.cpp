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

bool sortbysec(const P &a, const P &b){
    return (a.second > b.second);
}

void Main() {
    ll n; cin >> n;
    map<int, int> omod, zmod; // one (mod2), zero (mod2)
    rep(i, n){
        ll v; cin >> v;
        if (i % 2 == 0){
            if (zmod.find(v) != zmod.end()){zmod[v] += 1;}else{zmod[v] = 1;}
        } else {
            if (omod.find(v) != omod.end()){omod[v] += 1;}else{omod[v] = 1;}
        }
    }
    vector<P> ovec, zvec;
    for (auto v: omod){ovec.push_back(make_pair(v.first, v.second));}
    for (auto v: zmod){zvec.push_back(make_pair(v.first, v.second));}

    sort(ovec.begin(), ovec.end(), sortbysec);
    sort(zvec.begin(), zvec.end(), sortbysec);

    if (ovec.at(0).first != zvec.at(0).first){
        cout << n - ovec.at(0).second - zvec.at(0).second << endl;
    } else {
        ll ans1 = -INF, ans2 = -INF;
        // if we use second elem in ovec
        if (ovec.size() == 1 && zvec.size() == 1){
            cout << min(ovec.at(0).second, zvec.at(0).second) << endl;
        } else {
            if (ovec.size() > 1){ans1 = n - ovec.at(1).second - zvec.at(0).second;}
            if (zvec.size() > 1){ans2 = n - ovec.at(0).second - zvec.at(1).second;}
            ll ans = (ans1 >= ans2) ? ans2 : ans1;
            cout << ans << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
