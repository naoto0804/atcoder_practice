#include "template.hpp"

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

    // string /////////////////////////////////////////////////
    string s = "hoge";

    // insert and delete
    s.insert(s.begin() + 2, '-');
    cout << s << endl; // ho-ge
    s.erase(s.begin() + 1, s.begin() + 3);
    cout << s << endl; // hge

    // find
    cout << s.find('g') << endl; // g is 1st element in hge

    // vector /////////////////////////////////////////////////
    // init
    vector<int> X(N);
    // for loop
    for (int i = 0; i < N; i++){
        cout << X[i] << " " << endl;
    }
    // sort
    sort(X.begin(), X.end(), greater<int>()); // 昇順 ascending
    sort(X.begin(), X.end(), greater<int>()); // 降順 descending
    // max
    cout << *max_element(X.begin(), X.end()) << endl;

    // map ////////////////////////////////////////////////////
    map<int, int> x;
    x[2] = 1;
    x[3] = 1;

    // iterate over key and value
    for (auto it : x) {
        cout << it.first << " " << it.second << endl;
    }

    // mathematics /////////////////////////////////////////////////
}
