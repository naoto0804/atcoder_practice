#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int x = min(b, d) - max(a, c);
    if(x<=0) cout << 0 << endl;
    else cout << x << endl;
}