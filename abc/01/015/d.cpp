#include<iostream>
#include<vector>
using namespace std;

int main(){
  int W;
  cin >> W;

  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  vector<int> B(N);

//   for (int i = 0; i < N; i++) {
//     cin >> A.at(i) >> B.at(i);
//     cout << A.at(i) << B.at(i) << endl;
//   }

  vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(K + 1, vector<int>(W + 1, 0)));
  for (int i = 0; i < W + 1; i++) {
      for (int j = 0; j < K + 1; j++) {
          dp[i][j][0] = 0;
        //   for (int k = 0; k < N + 1; k++) {
        //       if (i - A[k - 1] > 0) {
        //           dp[i][j][k] = max(dp[i][j][k - 1], dp[i - A[k - 1]][j - 1][k - 1] + B[k - 1]);
        //       } else {
        //           dp[i][j][k] = dp[i][j][k - 1];
        //       }
        //   }
      }
//   cout << *max_element(dp.begin(), dp.end()) << endl;
  }
}
