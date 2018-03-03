#include <bits/stdc++.h>
using namespace std;
int t, n, x, kase = 1;
double dp[100005], p;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%lf%d", &n, &p, &x);
        for(int i = 1; i <= n; ++i) {
            dp[i] = (dp[i - 1] + 1.0) / (1.0 - p);
        }
        double ans = 1e10;
        for(int i = 1; i <= n; ++i) {
            ans = min(ans, (n % i) * 1.0 * dp[n / i + 1] + (i - n % i) * dp[n / i] + i * x);
        }
        printf("Case #%d: %.6lf\n", kase++, ans);
    }
    return 0;
}