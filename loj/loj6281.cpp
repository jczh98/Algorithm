#include <bits/stdc++.h>
using namespace std;
int n, a[50005], opt, l, r, c, sum[50005], bl[50005], len, flag[50005];
inline void blsqrt(int x) {
    if(flag[x]) return;
    flag[x] = 1; sum[x] = 0;
    for(int i = (x - 1) * len + 1; i <= x * len; ++i) {
        a[i] = int(sqrt(a[i] * 1.0)); sum[x] += a[i]; if(a[i] > 1) flag[x] = 0;
    }
}
int main() {
    scanf("%d", &n); len = int(sqrt(n * 1.0));
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); bl[i] = (i - 1) / len + 1; sum[bl[i]] += a[i];
    }
    for(int kase = 1; kase <= n; ++kase) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if(opt == 0) {
            for(int i = l; i <= min(r, bl[l] * len); ++i) {
                sum[bl[l]] -= a[i]; a[i] = int(sqrt(a[i] * 1.0)); sum[bl[l]] += a[i];
            }
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * len + 1; i <= r; ++i) {
                    sum[bl[r]] -= a[i]; a[i] = int(sqrt(a[i] * 1.0)); sum[bl[r]] += a[i];
                }
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) {
                blsqrt(i);
            }
        }else {
            int ans = 0;
            for(int i = l; i <= min(r, bl[l] * len); ++i) ans += a[i];
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * len + 1; i <= r; ++i) {
                    ans += a[i];
                }
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) {
                ans += sum[i];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
