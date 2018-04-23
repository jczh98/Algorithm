#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long LL;
int n, m, k, val[600][600], pre[600][600];
LL dp[600][600];
char table[600][600];
int main() {
    memset(dp, 127, sizeof(dp));
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) scanf("%s", table[i] + 1);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            pre[i][j] = pre[i][j - 1];
            if(table[i][j] == '1') pre[i][j]++;
        }
        for(int j = 0; j <= m; ++j) val[i][j] = inf; val[i][pre[i][m]] = 0;
        for(int j = 1; j <= m; ++j) {
            if(table[i][j] == '0') continue;
            for(int l = m; l >= j; --l) {
                if(table[i][l] == '1') {
                    int now = pre[i][m] - pre[i][l] + pre[i][j - 1];
                    val[i][now] = min(val[i][now], l - j + 1);
                }
            }
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            for(int l = 0; l <= j; ++l) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - l] + val[i][l]);
            }
        }
    }
    LL ans = inf;
    for(int i = 0; i <= k; ++i) ans = min(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}