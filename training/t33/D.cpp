#include <bits/stdc++.h>
using namespace std;
int t, n, k, ans;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        ans = (k - 1) % 3;
        for(int i = 4; i <= n; i++) {
            ans = (ans + k) % i;
        }
        printf("%d ", ans + 1);
        ans = (k - 1) % 2;
        for(int i = 3; i <= n; i++) {
            ans = (ans + k) % i;
        }
        printf("%d ", ans + 1);
        ans = 0;
        for(int i = 2; i <= n; i++) {
            ans = (ans + k) % i;
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}