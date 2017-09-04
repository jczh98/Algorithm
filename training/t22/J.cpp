#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
char str[MAXN];
int q, sum[MAXN], len, k, head, tail, que[MAXN], ans;
int main() {
    scanf("%s", str + 1);
    len = strlen(str + 1);
    for(int i = 1; i <= len; i++){
        if(str[i] == '1') {
            sum[i] = sum[i - 1] + 1;
        }else sum[i] = sum[i - 1];
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d", &k);
        head = 1; tail = 0;
        ans = 0;
        for(int i = 0, j = 0; i < len; i++) {
            while(j <= len && sum[j] - sum[i] <= k) {
                while(head <= tail && (j - 2 * sum[j]) >= (que[tail] - 2 * sum[que[tail]])) {
                    tail--;
                }
                que[++tail] = j++;
            }
            while(head <= tail && que[head] <= i) head++;
            if(head <= tail) ans = max(ans, (que[head] - i) - 2*(sum[que[head]] - sum[i]) + k);
        }
        ans = max(ans, 0);
        ans = min(ans ,len-sum[len]);
        printf("%d\n", ans);
    }
    return 0;
}