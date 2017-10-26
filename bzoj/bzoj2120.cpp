#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20005;
int n, m, x, y, c[MAXN], block, block_cnt, belong[MAXN], l[MAXN], r[MAXN], pos[1000005], last[MAXN], pre[MAXN];
char ss[10];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    block = sqrt(n * 1.0);
    if(n % block) block_cnt = n / block + 1; else block_cnt = n / block;
    for(int i = 1; i <= block_cnt; ++i) l[i] = (i - 1) * block + 1, r[i] = i * block; r[block_cnt] = n;
    for(int i = 1; i <= n; ++i) {
        last[i] = pos[c[i]]; pos[c[i]] = i; pre[i] = last[i];
    }
    for(int i = 1; i <= block_cnt; ++i) sort(last + l[i], last + r[i] + 1);
    for(; m; --m) {
        scanf("%s%d%d", ss, &x, &y);
        if(ss[0] == 'Q') {
            int ans = 0;
            if(belong[x] == belong[y]) {
                for(int i = x; i <= y; ++i) if(pre[i] < x) ++ans;
            }else {
                for(int i = x; i <= r[belong[x]]; ++i) if(pre[i] < x) ++ans;
                for(int i = l[belong[y]]; i <= y; ++i) if(pre[i] < x) ++ans;
                for(int i = belong[x] + 1; i < belong[y]; ++i) ans += lower_bound(last + l[i], last + r[i] + 1, x) - (last + l[i]);
            }
            printf("%d\n", ans);
        }else {
            for(int i = 1; i <= n; ++i) pos[c[i]] = 0;
            c[x] = y;
            pos[c[x]] = 0;
            for(int i = 1; i <= n; ++i) {
                last[i] = pos[c[i]]; pos[c[i]] = i; pre[i] = last[i];
            }
            for(int i = 1; i <= block_cnt; ++i) sort(last + l[i], last + r[i] + 1);
        }
    }
    return 0;
}

