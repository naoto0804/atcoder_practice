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

/**
 * Library
 * --------------------------------------------------------
 */
class UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> size;
    vector<vector<int>> group;
public:
    UnionFind(int n = 1) {
        par.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        group.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            par[i] = i;
            rank[i] = 0;
            size[i] = 1;
            group[i].push_back(i);
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            int r = find(par[x]);
            return par[x] = r;
        }
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }

    bool unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        } else {
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
            par[y] = x;
            size[x] += size[y];
            return true;
        }
    }

    int get_size(int x) {
        return size[find(x)];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (group[x].size() > group[y].size()) {
            swap(x, y);
        }
        copy(group[y].begin(), group[y].end(), back_inserter(group[x]));
        group[y].clear();
        par[y] = x;
    }
};
/**
 * --------------------------------------------------------
 */

using T = tuple<ll, ll, ll>;
// https://www.geeksforgeeks.org/sorting-vector-tuple-c-descending-order/
bool sortdesc(T& n1, T& n2) {
    return get<0>(n1) > get<0>(n2);
}

void Main() {
    ll N, M; cin >> N >> M;
    vector<T> v; // (year, node1, node2)
    rep(i, M){
        ll a, b, y; cin >> a >> b >> y;
        a--; b--;
        v.push_back(make_tuple(y, a, b));
    }
    sort(v.begin(), v.end(), sortdesc);

    ll Q; cin >> Q;
    vector<ll> V(Q), W(Q);
    rep(i, Q){
        ll v, w; cin >> v >> w; v--;
        V.at(i) = v; W.at(i) = w;
    }

    vector<int> indices(Q), answers(Q);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&W](ll i1, ll i2) {
        return W[i1] > W[i2]; // 降順
    });

    // 新しい方から橋を足していってunion-find
    UnionFind un(N);
    ll uf_ind = 0;
    for (auto ind: indices){
        ll current_year = W.at(ind);
        while (true){ // 今の年より未来の設立年の橋を足す
            if (uf_ind < M && get<0>(v.at(uf_ind)) > current_year){
                un.unit(get<1>(v.at(uf_ind)), get<2>(v.at(uf_ind)));
                uf_ind++;
            } else {
                break;
            }
        }
        answers.at(ind) = un.get_size(V.at(ind));
    }
    for (auto a: answers){cout << a << endl;}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
