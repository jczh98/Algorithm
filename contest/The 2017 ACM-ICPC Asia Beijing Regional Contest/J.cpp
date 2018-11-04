#include <bits/stdc++.h>
#define ff(i, x, y) for(int i = x; i <= y; i++)
#define fs(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
typedef long long ll;
int n, l, r;
ll dp[110][110][110], pre[110], mes[110];
int main() {
    while(scanf("%d%d%d", &n, &l, & r) != EOF) {
        ff(i, 1, n) {
            scanf("%lld", &mes[i]);
            pre[i] = mes[i];
        }
        ff(i, 1, n)
        ff(j, i, n)
        ff(p, 1, n)
        dp[i][j][p] = 1e8;
        ff(i, 1, n)
        pre[i] += pre[i - 1];
        ff(i, 1, n)
        ff(j, i, n) {
            dp[i][j][j - i + 1] = 0;
            if(j - i + 1 <= r && j - i + 1 >= l)
                dp[i][j][1] = pre[j] - pre[i - 1];
        }
        ff(i, 1, n) {
            ff(j, i, n) {
                ff(p, 1, j - i)
                ff(k, i, j - 1) {
                    if(p == 1) {
                        ll mi = 1e8;
                        ff(tp, l - 1, r - 1)
                        mi = min(dp[k + 1][j][tp], mi);
                        dp[i][j][1] = min(dp[i][j][1], dp[i][k][1] + mi + pre[j] - pre[i - 1]);
                    }
                    else
                        dp[i][j][p] = min(dp[i][j][p], dp[i][k][1] + dp[k + 1][j][p - 1]);
                }
            }
        }
        if(dp[1][n][1] == 1e8) printf("0\n");
        else
            printf("%lld\n", dp[1][n][1]);
    }
    return 0;
}