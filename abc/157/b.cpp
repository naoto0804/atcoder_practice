#include "template.hpp"

int main()
{
    vvi A(3, vi(3)), board(3, vi(3, 0));
    rep(i, 3){rep(j, 3) { cin >> A[i][j];}}

    int N;
    cin >> N;

    vi B(N);
    rep(i, N){cin >> B[i];}
    rep(i, N){rep(j, 3){rep(k,3) {if (B[i] == A[j][k]){board[j][k] = 1;}}}}
    // rep(i, 3){rep(j, 3) {cout << board[i][j] << endl;}}

    bool bingo = false;

    // row
    rep(i, 3){
        int row_sum = 0;
        int col_sum = 0;
        rep(j, 3){
            row_sum += board[i][j];
            col_sum += board[j][i];
            if (row_sum == 3 || col_sum == 3) {bingo = true;}
        }
    }

    // diagonal
    int diag1_sum = 0;
    int diag2_sum = 0;
    rep(i, 3){
        diag1_sum += board[i][i];
        diag2_sum += board[i][2 - i];
    }
    if (diag1_sum == 3 || diag2_sum == 3) {bingo = true;}
    if (bingo) {cout << "Yes" << endl;} else {cout << "No" << endl;}
}
