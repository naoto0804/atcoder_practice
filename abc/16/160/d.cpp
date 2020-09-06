#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    map<int, int> mp;
    for (int i = 1; i < N; i++)
    {
        mp[i] = 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i >= j){
                /* code */
                continue;
            } else {
                int key;
                if (i == X and Y == j) {
                    key = 1;
                } else {
                    // key = int(min(j - i, math.fabs(X - i) + math.fabs(Y - j) + 1))
                    key = min(abs(X - i) + abs(Y - j) + 1, j - i);
                }
                mp[key] += 1;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cout << mp[i] << endl;
    }
}
