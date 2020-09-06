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
  int X;
  cin >> X;

  int res;
  int ans = 0;
  ans += (X / 500) * 1000;
  res = X % 500;
  ans += (res / 5) * 5;
  cout << ans << endl;
}
