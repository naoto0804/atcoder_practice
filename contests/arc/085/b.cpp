#include "bits/stdc++.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N, Z, W;
    cin >> N >> Z >> W;

    vector<int> a(N);
    rep(i, N) { cin >> a.at(i); }
    if (N == 1) {
        cout << abs(a[0] - W) << endl;
    } else {
        cout << max(abs(a[N-1] - W), abs(a[N-1] - a[N-2])) << endl;
    }
}
