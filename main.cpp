#include "template.hpp"

// nまでの整数の持つ最小の素因数を格納した配列(サイズはn+1, 0を含んでいる)
// e.g., 3 = get_min_factor(9)[9]
// 複数の数を高速に素因数分解するのに使う
std::vector<size_t> get_min_factor(size_t n)
{
    std::vector<size_t> res(n + 1);
    std::iota(res.begin(), res.end(), 0); // start from 0, increment one by one
    for (size_t i = 2; i * i < n + 1; ++i)
    {
        if (res[i] < i)
            continue;
        for (size_t j = i * i; j < n + 1; j += i)
            if (res[j] == j)
                res[j] = i;
    }
    return res;
}

// 1~Nまでに関してすべて素因数分解
// coutする部分をmapへの加算にすると約数がカウントできる
void enumerate_all_prime_factors()
{
    size_t N = 10;
    std::vector<size_t> min_factor = get_min_factor(N);
    rep(i, N + 1){
        int num = i;
        while (num != min_factor[num]){
            cout << i << " " << min_factor[num] << endl;
            num /= min_factor[num];
        }
        cout << i << " " << num << endl;
    }
}
