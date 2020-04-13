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

void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out)
{
	// construct a stream from the string
	std::stringstream ss(str);

	std::string s;
	while (std::getline(ss, s, delim)) {
		out.push_back(s);
	}
}

float expectation(ll n){return (float)(n + 1) / 2;}

void Main() {
    int N, K;
    cin >> N >> K;
    int A[N];
    float S[N + 1];
    S[0] = 0;
    rep(i, N){
        cin >> A[i];
        S[i + 1] = S[i] + expectation(A[i]);
    }
    float ans = -1.0;
    rep(i, N - K + 1){
        float tmp = S[i + K] - S[i];
        if (ans < tmp){ans = tmp;}
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
