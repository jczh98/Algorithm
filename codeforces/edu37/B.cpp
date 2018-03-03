#include <bits/stdc++.h>
using namespace std;
int t, n, l[5005], r[5005], ans[5005];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &l[i], &r[i]);
        }
        int cur = l[1];
        for(int i = 1; i <= n; ++i) {
            cur = max(cur, l[i]);
            if (r[i] >= cur) {
                ans[i] = cur;
                cur++;
            } else {
                ans[i] = 0;
            }
        }
        for(int i = 1; i <= n; ++i) {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}
