#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
int n, a[20000], flag = 0, dp[20000];
int start, end, maxm = -1;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= 0) flag = 1;
    }
    if (!flag) {
        printf("0 %d %d\n", a[1], a[n]);
    } else {
        int tmp;
        for (int i = 1; i <= n; ++i) {
            dp[i] = max(dp[i-1] + a[i], a[i]);
            if (dp[i] == a[i]) {
                tmp = i;
            }
            if (maxm < dp[i]) {
                end = i;
                start = tmp;
                maxm = dp[i];
            }
        }
        printf("%d %d %d\n", maxm, a[start], a[end]);
    }
}
