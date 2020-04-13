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

int get_num_digits(ll n){
    return (int)log10(n) + 1;
}

ll solve(const string S){
    // dp[決定した桁数][N以下確定か][4または9を含むか]
    ll dp[32][2][2];
    rep(i, 32){rep(j, 2){rep(k, 2){dp[i][j][k] = 0;}}}
    dp[0][0][0] = 1;
    int L = S.size();
    rep(i, L){
        const int D = S[i] - '0';
        rep(j, 2){
            rep(k, 2){
                for ( int d = 0; d <= ( j ? 9 : D ); ++d ){ // 以下な数しか通さないための分岐
                    // コツ: DP[i][j][k]から足し込む先を式として1行で無理やり書いてしまう
                    // i -> i+1
                    // j -> もとから1なら必ず1, そうでなければ次の桁がD以下
                    // k -> もとから1なら必ず1, そうでなければ次の桁が4or9
                    dp[i+1][j || (d < D)][k || d == 4 || d == 9] += dp[i][j][k];
                }
            }
        }
    }
    return dp[L][0][1] + dp[L][1][1];
}

// 典型的な桁DP
void Main() {
    ll A, B;
    cin >> A >> B;
    // int L_A = get_num_digits(A);
    // int L_B = get_num_digits(B);
    cout << solve(to_string(B)) - solve(to_string(A-1)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
