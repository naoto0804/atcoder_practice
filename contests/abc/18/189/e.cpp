// ctrl+shift+b
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, m, n) for (ll i = m; i < (ll)(n); i++)
#define rrep(i, n, m) for (ll i = n; i >= (ll)(m); i--)
#define sz(s) (ll)(s.size())

const int dx[3] = {-1, 0, -1};
const int dy[3] = {0, -1, -1};
// const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

template<typename T>
struct mat {
    // 行列m
    vector<vector<T>> m;
    // コンストラクタ:第1引数⇒行数、第2引数⇒列数、第3引数⇒初期値
    mat():m(vector<vector<T>>()){}
    mat(ll h,ll w):m(vector<vector<T>>(h,vector<T>(w))){}
    mat(ll h,ll w, T d):m(vector<vector<T>>(h,vector<T>(w,d))){}
    // 添字演算子
    vector<T> operator[](const ll i) const {return m[i];} //読み取り
    vector<T>& operator[](const ll i){return m[i];} //書き込み
    // 行数・列数
    ll nrow = (ll)(m.size());
    ll ncol = (ll)(m[0].size());
    // 行列同士の演算
    mat& operator=(const mat& a){return *a;}
    mat& operator+=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
    mat& operator-=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;}
    mat& operator*=(const mat& a){assert(ncol == a.nrow);mat<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol)m2[i][j] += m[i][k]*a[k][j];ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]; return *this;}
    mat operator+(const mat& a) const { return mat(*this) += a;}
    mat operator-(const mat& a) const { return mat(*this) -= a;}
    mat operator*(const mat& a) const { return mat(*this) *= a;}
    bool operator==(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}
    // 行列とスカラの演算
    mat& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
    mat& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
    mat& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
    mat& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
    mat operator+(const T& a) const { return mat(*this) += a;}
    mat operator-(const T& a) const { return mat(*this) -= a;}
    mat operator*(const T& a) const { return mat(*this) *= a;}
    mat operator/(const T& a) const { return mat(*this) /= a;}
    // 回転（degの数だけ時計回りに90度回転）
    mat& rot(ll deg){
        mat<T> m2(ncol, nrow);
        if(deg == 1 || deg == 3){
            if(deg == 1)rep(i,nrow)rep(j,ncol)m2[j][nrow -i -1] = m[i][j];
            if(deg == 3)rep(i,nrow)rep(j,ncol)m2[ncol -j -1][i] = m[i][j];
            swap(ncol,nrow); // 列数と行数を入れ替える
            m.resize(nrow);rep(i,nrow)m[i].resize(ncol); //リサイズ
        }
        if(deg == 2)rep(i,nrow)rep(j,ncol)m2[nrow -i -1][ncol -j -1] = m[i][j];
        rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j];
        return *this;
    }
    // 標準出力
    void show(){
        rep(i,nrow)rep(j,ncol){
            if(j != 0)cout << " ";
            cout << m[i][j];
            if(j==ncol-1)cout << endl;
        }
        return ;
    }
};

void Main() {
    ll N; cin >> N;
    vector<mat<ll>> xyz;
    rep(i, N){
        mat<ll> m(3, 1, 1); cin >> m[0][0] >> m[0][1];
        xyz.push_back(m);
    }

    ll M; cin >> M;
    vector<mat<ll>> ops;
    rep(i, M){
        ll num; cin >> num;
        mat<ll> m(3, 3, 0);
        if (num == 1){
            m[0][0] = m[1][1] = 0;
            m[1][0] = 1;
            m[0][1] = -1;
            m[2][2] = 1;
        } else if (num == 2){
            m[0][0] = m[1][1] = 0;
            m[1][0] = -1;
            m[0][1] = 1;
            m[2][2] = 1;
        } else if (num == 3){
            ll p; cin >> p;
            m[0][0] = -1;
            m[0][2] = 2 * p;
            m[1][1] = 1;
            m[2][2] = 1;
        } else {
            ll p; cin >> p;
            m[0][0] = 1;
            m[1][1] = -1;
            m[1][2] = 2 * p;
            m[2][2] = 1;
        }
        // m.show();
        ops.push_back(m);
    }

    ll Q; cin >> Q;
    vector<P> pairs;
    rep(i, Q){
        ll a, b; cin >> a >> b;
        pairs.push_back(make_pair(a, b));
    }

    mat<ll> tmp(3, 3, 0);
    rep(i, 3){tmp[i][i] = 1;}
    vector<mat<ll>> matrices(M + 1);
    matrices.at(0) = tmp;
    rep(i, M){
        mat<ll> hoge = ops.at(i) * tmp;
        // hoge.show();
        matrices.at(i + 1) = hoge;

        // tmp = hoge;
        // ops.at(i).show();d
        // tmp.show();
        // cout << endl;
        // tmp = ops.at(i) * tmp;
        // mat<ll> fuga = ops.at(i);
        // mat<ll> hoge = fuga * tmp;

        // matrices.push_back(hoge);
        // tmp = hoge;
    }
    rep(i, Q){
        P p = pairs.at(i);
        mat<ll> ans = matrices.at(p.first) * xyz.at(p.second - 1);
        rep(i, 2){cout << ans[i][0] << " ";}
        cout << endl;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
