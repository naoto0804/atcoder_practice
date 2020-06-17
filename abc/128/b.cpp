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

template <class _A, class _B, class _Compare=less<_A> >
class MMap : public set < pair< _A, _B >, _Compare >
{
        public :
                MMap():set< pair< _A, _B >, _Compare >(){};
                ~MMap(){};
};

template< typename InPair >
struct MMapComp{
        bool operator() (InPair a , InPair b){
                if( a.first == b.first ) return a.second > b.second;
                else
                        return a.first < b.first;
        }
};

void Main() {
    ll N; cin >> N;
    MMap<string, ll, MMapComp< pair<string , ll> > > x;
    map<pair<string, ll>, ll> y;
    rep(i, N){string s; ll p; cin >> s >> p; x.insert(make_pair(s, p)); y[make_pair(s, p)] = i + 1;}
    for( MMap<string, ll >::iterator it = x.begin(); it != x.end(); it++ ){
        // cout << (*it).first << "\t" << (*it).second << endl;
        cout << y[make_pair((*it).first, (*it).second)] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
