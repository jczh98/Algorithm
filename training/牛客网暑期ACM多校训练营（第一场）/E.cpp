#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n, m, k, s[100010], nxt[100010][11];
ll ans, dp[100010][11];
int main() {
    while(~scanf("%d%d%d", &n, &m, &k)) {
        memset(dp, 0, sizeof(dp)); ans = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", &s[i]);
        for(int i = 1; i <= k; ++i) nxt[n][i] = n+1;
        for(int i = n; i >= 1; --i) {
            for(int j = 1; j <= k; ++j) {
                nxt[i - 1][j] = nxt[i][j];
            }
            nxt[i - 1][s[i]] = i;
        }
        dp[0][0]=1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j <= m ; ++j) {
                for(int l = 1; l <= k; ++l) {
                    if(j+nxt[i][l]-i-1 <= m)
                        (dp[nxt[i][l]][j+nxt[i][l]-i-1] += dp[i][j]) %= mod;
                }
            }
        }
        for(int i = 0; i <= m; ++i) (ans += dp[n-i][m-i]) %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}