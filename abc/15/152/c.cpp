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

class mint {
public:
    long long x;

    constexpr mint(long long x = 0) : x((x % MOD + MOD) % MOD) {}

    constexpr mint operator-() const {
        return mint(-x);
    }

    constexpr mint &operator+=(const mint &rhs) {
        if ((x += rhs.x) >= MOD) x -= MOD;
        return *this;
    }

    constexpr mint &operator-=(const mint &rhs) {
        if ((x += MOD - rhs.x) >= MOD) x -= MOD;
        return *this;
    }

    constexpr mint &operator*=(const mint &rhs) {
        (x *= rhs.x) %= MOD;
        return *this;
    }

    constexpr mint operator+(const mint &rhs) const {
        mint res(*this);
        return res += rhs;
    }

    constexpr mint operator-(const mint &rhs) const {
        mint res(*this);
        return res -= rhs;
    }

    constexpr mint operator*(const mint &rhs) const {
        mint res(*this);
        return res *= rhs;
    }

    [[nodiscard]] constexpr mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    [[nodiscard]] constexpr mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator/=(mint rhs) {
        return *this *= rhs.inv();
    }

    mint operator/(const mint rhs) const {
        return mint(*this) /= rhs;
    }

    constexpr bool operator==(const mint &rhs) const noexcept {
        return this->x == rhs.x;
    }

    constexpr bool operator!=(const mint &rhs) const noexcept {
        return this->x != rhs.x;
    }

    bool operator<(const mint &rhs) const noexcept {
        return this->x < rhs.x;
    }

    bool operator>(const mint &rhs) const noexcept {
        return this->x > rhs.x;
    }

    bool operator<=(const mint &rhs) const noexcept {
        return this->x <= rhs.x;
    }

    bool operator>=(const mint &rhs) const noexcept {
        return this->x >= rhs.x;
    }

    friend istream &operator>>(istream &is, mint &a) {
        long long t;
        is >> t;
        a = mint(t);
        return is;
    }

    friend ostream &operator<<(ostream &os, const mint &a) {
        return os << a.x;
    }
};

void Main() {
    ll N;
    cin >> N;
    vector<ll> P(N);
    rep(i, N){cin >> P.at(i);}

    ll minimum = INF;
    ll cnt = 0;
    rep(i, N){
        if (P.at(i) < minimum){
            cnt += 1;
            minimum = P.at(i);
        }
    }
    cout << cnt << endl;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
