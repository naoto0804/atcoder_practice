#include "template.hpp"

int main()
{
    int N, M;
    cin >> N >> M;

    bool flag = true;
    vi cand(N + 1, -1); // -1 means no cand at that pos
    rep1(i, M){
        int s, c;
        cin >> s >> c;
        if (s == 1 && c == 0 && N > 1){flag = false; break;}
        if (cand[s] < 0){
            cand[s] = c;
        } else {
            if (cand[s] != c){flag = false; break;}
        }
    }
    rep1(i, M){if (cand[i] == -1){cand[i] = 0;}}

    if (flag){
        int ans = 0;
        rep1(i, M){ans = ans * 10 + cand[i];}
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }
}
