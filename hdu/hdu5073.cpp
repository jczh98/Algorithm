#include <bits/stdc++.h>
using namespace std;
const int N = 50050;
double sum1[N], sum2[N], a[N], ans;
int t, n, k;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) scanf("%lf", &a[i]);
        ans = 0;
        if(k == n) { printf("0\n"); continue;}
        sort(a + 1, a + n + 1);
        sum1[0] = sum2[0] = 0.0;
        for(int i = 1; i <= n; i++) {
            sum1[i] = sum1[i - 1] + a[i] * a[i];
            sum2[i] = sum2[i - 1] + a[i];
        }
        int t = n - k;
        for(int i = 1; i + t <= n + 1; ++i) {
            double p = sum1[i + t - 1] - sum1[i - 1] - (sum2[i + t - 1] - sum2[i - 1]) * (sum2[i + t - 1] - sum2[i - 1]) / t;
            if (i == 1) ans = p; else ans = min(ans, p);
        }
        printf("%.9lf\n", ans);
    }
    return 0;
}
