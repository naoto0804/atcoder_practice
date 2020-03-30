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
    // see http://vivi.dyndns.org/tech/cpp/map.html
    map<int, int> x;
    x[2] = 1;
    x[3] = 1;
    // cout << x.find(2) != x.end() << endl; // whether 2 exists in x
    // iterate over key and value
    for (auto it : x) {
        cout << it.first << " " << it.second << endl;
    }

    // set ////////////////////////////////////////////////////
    // see http://vivi.dyndns.org/tech/cpp/set.html
    set<int> st{3, 1, 4, 6, 7};
    st.insert(2);
    st.erase(3);
    return 1;

    // priority_queue
    // 大きい方からも小さい方からも取り出せる
    // https://qiita.com/y_shindoh/items/17d9fa334a2cb8e74bfa
    int a[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};
    priority_queue<int> q; // 大きい方から取り出し
    // std::priority_queue< int, std::vector<int>, std::greater<int> > q; 小さい方から取り出し
    q.push(33);
    q.top();  // element of the first priority
    q.pop();  // remove a.top()

    // mathematics /////////////////////////////////////////////////
}
