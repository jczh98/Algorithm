#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;
typedef long long LL;
int n, x, y, z, a[500005];
LL sum[2 * MAX], cnt[2 * MAX], ans;
int main() {
    scanf("%d%d%d", &n, &x, &y);
    z = x / y;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        sum[a[i]] += a[i];
    }
    ans = x * 1LL * n * 1LL;
    for(int i = 1; i < 2 * MAX; i++) {
        sum[i] += sum[i - 1];
        cnt[i] += cnt[i - 1];
    }
    for(int g = 2; g < MAX; g++) {
        LL t = 0;
        for(int k = g; k < 2 * MAX; k += g) {
            if(g - z > 1) {
                t += (cnt[k - z - 1] - cnt[k - g]) * x;
            }
            int f = max(k - z, k - g + 1);
            t += ((cnt[k - 1] - cnt[f - 1]) * k - (sum[k - 1] - sum[f - 1])) * y;
        }
        ans = min(ans, t);
    }
    cout << ans << endl;
    return 0;
}

