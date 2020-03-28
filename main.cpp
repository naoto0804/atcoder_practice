#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;

    vector<int> a(N-1), b(N-1);
    rep(i, N-1) { cin >> a.at(i) >> b.at(i); cout << a.at(i) << b.at(i);}
    // if (N == 1) {
    //     cout << abs(a[0] - W) << endl;
    // } else {
    //     cout << max(abs(a[N-1] - W), abs(a[N-1] - a[N-2])) << endl;
    // }
}
