#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, a[3005];
LL dp[3005][3005], s[3005], q[3005];
double slope(int t, int k, int j) {
    return ((dp[t][j - 1] + s[t] * s[t]) - (dp[k][j - 1] + s[k] * s[k])) * 1.0 / (s[t] - s[k]);
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); s[i] = s[i - 1] + a[i];
        dp[i][1] = s[i] * s[i];
    }
    for(int j = 2; j <= m; ++j) {
        int l = 1, r = 0;
        for(int i = 1; i <= n; ++i) {
            while(l < r && slope(q[l], q[l + 1], j) < 2.0 * s[i]) ++l;
            int t = q[l];
            dp[i][j] = dp[t][j - 1] + (s[i] - s[t]) * (s[i] - s[t]);
            while(l < r && slope(q[r], i, j) < slope(q[r - 1], q[r], j)) --r;
            q[++r] = i;
        }
    }
    cout << dp[n][m] * m - s[n] * s[n] << endl;
    return 0;
}