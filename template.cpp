#include"bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a;
  cin >> a;

  int N, M;
  cin >> N >> M;

  vector<int> vec(a);
  for (int i = 0; i < a; i++) {
    cin >> vec.at(i);
  }
  cout << a << endl;
}
