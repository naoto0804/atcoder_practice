#include"bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;

  vector<int> P(A), Q(B), R(C), PQR(X + Y + C);

  rep(i, A) { cin >> P.at(i); }
  rep(j, B) { cin >> Q.at(j); }
  rep(k, C) { cin >> R.at(k); }

  sort(P.begin(), P.end(), greater<int>());
  sort(Q.begin(), Q.end(), greater<int>());

  rep(i, X) { PQR[i] = P[i]; }     // only keep biggest X examples from P
  rep(i, Y) { PQR[i + X] = Q[i]; } // only keep biggest X examples from Q
  rep(i, C) { PQR[i + X + Y] = R[i]; }
  sort(PQR.begin(), PQR.end(), greater<int>());

  ll ans = 0;
  rep(i, X + Y) { ans += PQR[i]; }
  cout << ans << endl;
}
