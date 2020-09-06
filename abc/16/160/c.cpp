#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;

  vector<int> A(N + 1);
  vector<int> diff(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  A[N] = A[0] + K;
  for (int i = 0; i < N; i++) {
      diff[i] = A[i + 1] - A[i];
  }
  double max = *max_element(diff.begin(), diff.end());
  cout << K - int(max) << endl;
}
