#include"bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

inline ll square(ll x) { return x * x; }
inline ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
inline ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main() {
  int N;
  cin >> N;

  vector<ll> T(N);
  rep(i, N) { cin >> T.at(i); }
  ll ans = T[0];
  rep(i, N - 1) {ans = lcm(ans, T[i + 1]);}
  cout << ans << endl;
}
