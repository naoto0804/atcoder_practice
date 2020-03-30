#include "template.hpp"

int main()
{
    int N, M;
    int S[N], T[M];

    map<string, int> x;
    string s;

    cin >> N;
    rep(i, N){
        cin >> s;
        if (x.find(s) != x.end()){
            x[s] += 1;
        } else {
            x[s] = 1;
        }
    }

    cin >> M;
    rep(j, M){
        cin >> s;
        if (x.find(s) != x.end()){
            x[s] -= 1;
        } else {
            x[s] = -1;
        }
    }
    int ans = 0;
    for(auto itr = x.begin(); itr != x.end(); ++itr) {
        if (itr->second > ans){
            ans = itr->second;
        }
    }
    cout << ans << endl;
}
