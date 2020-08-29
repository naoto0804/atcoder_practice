// 別名 Osa_k法
// https://qiita.com/rsk0315_h4x/items/ff3b542a4468679fb409
// 拡張版; 区間篩（上のリンクから）

// その整数の持つ最小の素因数を格納した配列
// array having minimum prime of given x
vector<ll> sieve(ll n) {
    vector<ll> res(n);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i*i < n; ++i) {
        if (res.at(i) < i){continue;}
        for (int j = i * i; j < n; j += i)
        if (res.at(j) == j){res.at(j) = i;}
    }
    return res;
}

// O(loglogN)
// minimum_factor should be 0, 1, or prime
map<ll, ll> fast_prime_factorize(ll N, const vector<ll>& minimum_factor) {
    map<ll, ll> res;
    while (N > 1){
        ll prime = minimum_factor[N];
        N = N / prime;
        if (res.find(prime) != res.end()){
            res[prime]++;
        } else {
            res[prime] = 1;
        }
        if (prime < 2){break;}
    }
    return res;
}


void Main() {
    vector<ll> min_factor = sieve(1000);
    rep2(i, 1, 100){
        cout << "Num: " << i << endl;
        map<ll, ll> res = fast_prime_factorize(i, min_factor);
        for (auto a: res){
            cout << a.first << " " << a.second << endl;
        }
    }
}