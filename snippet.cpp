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

int main()
{
    // variable
    int N;
    long long NN;

    // if
    if (true) {} else {}

    // user IO
    cin >> N;
    cout << N;         // w/o new line
    cout << N << endl; // w/ new line

    vector<int> vec(N);
    for (int i = 0; i < N; i++){cin >> vec.at(i);}  // get array of int with size N

    // vector /////////////////////////////////////////////////
    // init
    vector<int> X(N);

    // for loop
    for (int i = 0; i < N; i++)
    {
        cout << X[i] << " " << endl;
    }

    // sort
    sort(X.begin(), X.end(), greater<int>()); // 昇順 ascending
    sort(X.begin(), X.end(), greater<int>()); // 降順 descending
}
