#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
int n, t, L, B, l[MAXN], b[MAXN], cnt_l[MAXN], cnt_b[MAXN];
double f[MAXN][MAXN];
int main() {
    freopen("C.in", "r", stdin);
    while(scanf("%d%d%d%d", &n, &t, &L, &B) != EOF) {
        if(n == 0 && t == 0 && L == 0 && B == 0) break;
        memset(cnt_l, 0, sizeof(cnt_l));
        memset(cnt_b, 0, sizeof(cnt_b));
        for(int i = 1; i <= L; i++) {
            scanf("%d", &l[i]);
            cnt_l[l[i]] = 1;
        }
        for(int i = 1; i <= B; i++) {
            scanf("%d", &b[i]);
            cnt_b[b[i]] = 1;
        }
        memset(f, 0, sizeof(f));
        f[1][0] = 1.0;
        for(int i = 1; i <= t; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 1; k <= 6; k++) {
                    int to;
                    if(j + k <= n) to = j + k;
                    else to = 2 * n - j - k;
                    if(cnt_b[to]) {
                        f[i + 1][0] += f[i][j] * 1.0 / 6.0;
                        continue;
                    }
                    if(cnt_l[to]) {
                        f[i + 2][to] += f[i][j] * 1.0 / 6.0;
                        continue;
                    }
                    f[i + 1][to] += f[i][j] * 1.0 / 6.0;
                }
            }
        }
        double ans = 0;
        for(int i = 1; i <= t + 2; i++) ans += f[i][n];
        printf("%.9f\n", ans);
    }
    return 0;
}

