#include "template.hpp"

int main()
{
    int N, M, T;
    cin >> N >> M >> T;
    int A[N], a[M], b[M], c[M];
    rep(i, N){cin >> A[i];}
    rep(i, M){cin >> a[i] >> b[i] >> c[i];}
    vi u(N - 1), v(N - 1), w(N - 1);
    rep(i, N - 1)
    {
        scanf("%d %d %d%*c", &u[i], &v[i], &w[i]);
        u[i]--;
        v[i]--;
        w[i] %= 2;
    }
    solve(N, u, v, w);
    return 0;
}
