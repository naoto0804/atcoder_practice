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
    sort(X.begin(), X.end()); // 昇順 ascending
    sort(X.begin(), X.end(), greater<int>()); // 降順 descending
    // max
    cout << *max_element(X.begin(), X.end()) << endl;

    // argsort
    vector<int> indices(N), array(N);
    iota(indices.begin(), indices.end(), 0);
    sort(indices.begin(), indices.end(), [&array](size_t i1, size_t i2) {
        return array[i1] < array[i2];
    });

    // binary search
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    auto iter = lower_bound(a.begin(), a.end(), 4); // key <= x なもののうち一番左の位置
    auto iter = upper_bound(a.begin(), a.end(), 4); // key < x なもののうち一番左の位置
    cout << binary_search(a.begin(), a.end(), 4) << endl; // 有無をboolで返す
    cout << *iter << endl; // 見つかった値を表示
    cout << iter - a.begin() << endl; // 0-based indexを表示

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
    auto it = st.find(6);
    if (it != st.end()){cout << *it << endl;}
    // return 1;

    // deque

    // priority_queue
    // 大きい方からも小さい方からも取り出せる
    // https://qiita.com/y_shindoh/items/17d9fa334a2cb8e74bfa
    int a[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};
    priority_queue<int> q; // 大きい方から取り出し
    // std::priority_queue< int, std::vector<int>, std::greater<int> > q; 小さい方から取り出し
    q.push(33);
    auto v = q.top();  // element of the first priority, queueだとfrontなので注意
    q.pop();  // remove a.top()

    // tuple
    tuple<int, int, int> tmp;
    int& cur_y = get<0>(tmp);
    int& cur_x = get<1>(tmp);
    int& cur_cost = get<2>(tmp);

    // pair
    pair<ll, ll> p = make_pair(1, 1);
    cout << p.first << endl;
    cout << p.second << endl;

    // mathematics /////////////////////////////////////////////////
}
