#include <bits/stdc++.h>
#define inf 0x7fffffff
using namespace std;
typedef long long LL;
LL n, ans, num;
LL p[17] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
void dfs(int k, LL now, LL cnt, int last) {
    if (k > 17) return;
    if (cnt > num) num = cnt, ans = now;
    if (cnt == num && now < ans) ans = now;
    for (int i = 1; i <= last; ++i) {
        if (now <= n / p[k]) {
            now = now * p[k];
            dfs(k + 1, now, cnt * (i + 1),  i);
        }
    }
}
int t;
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = 1; num = 1;
        scanf("%lld", &n);
        dfs(1, 1, 1,65);
        printf("%lld %lld\n", ans, num);
    }
    return 0;
}