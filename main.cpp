#include "template.hpp"

int main()
{
    string S;
    int N, Q, N_CHAR;
    cin >> N >> S >> Q;
    N_CHAR = 26;

    // vvi acc_cnt(N_CHAR, vi(N, 0));
    // first element is for each character
    vvi char_indices(N_CHAR);

    rep(i, N){
        char_indices[int(S[i]) - int('a')].push_back(i);
    }
    // for (auto v: char_indices[0]){cout << v << " " << endl;}
    rep(i, N){cout << i << " " << char_indices[i].size() << endl;}
}

// #include "template.hpp"

// int main()
// {
//     string S;
//     int N, Q, N_CHAR;
//     cin >> N >> S >> Q;
//     N_CHAR = 26;

//     // vvi acc_cnt(N_CHAR, vi(N, 0));
//     // first element is for each character
//     vvi acc_cnt(N_CHAR);
//     vi cnt(N_CHAR, 0);

//     rep(i, N_CHAR){acc_cnt[i].push_back(0);}
//     rep(i, N){
//         cnt[int(S[i]) - int('a')] += 1;
//         rep(j, N_CHAR){
//             cout << cnt[j] << " ";
//             acc_cnt[j].push_back(cnt[j]);
//         }
//         cout << endl;
//     }
//     // rep(i, N_CHAR){cout << i << " " << acc_cnt[i] << endl;}
//     rep(i, Q){
//         int q, ind, l, r;
//         char from_c, to_c;
//         cin >> q;
//         if (q == 1){
//             cout << "replace" << endl;
//             cin >> ind >> to_c;

//             from_c = S[ind - 1];
//             S[ind - 1] = to_c;

//             // decrement count for from_c
//             for (int j = l; j <= r; j++){
//                 acc_cnt[int(from_c) - int('a')][j] -= 1;
//                 acc_cnt[int(to_c) - int('a')][j] += 1;
//             }
//             cout << endl;
//         } else {
//             cout << "count" << endl;
//             cin >> l >> r;
//             int sum = 0;
//             rep(j, N_CHAR){
//                 if (acc_cnt[j][r] - acc_cnt[j][l - 1] > 0) { sum += 1;}
//             }
//             cout << sum << endl;
//         }
//     }
//     rep(l, N + 1){rep(m, N_CHAR){cout << acc_cnt[m][l] << " ";} cout << endl;}
// }
