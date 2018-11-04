#include <bits/stdc++.h>
using namespace std;
int n, a[100005], opt, l, r, c, bl[100005], blocks, add[100005];
vector<int> pre[100005];
inline void update(int x) {
    pre[x].clear();
    for(int i = (x - 1) * blocks + 1; i <= x * blocks; ++i) pre[x].push_back(a[i]);
    sort(pre[x].begin(), pre[x].end());
}
int main() {
    scanf("%d", &n); blocks = (int) sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); bl[i] = (i - 1) / blocks + 1;
        pre[bl[i]].push_back(a[i]);
    }
    int num = n % blocks == 0 ? n / blocks : n / blocks + 1;
    for(int i = 1; i <= num; ++i) {
        sort(pre[i].begin(), pre[i].end());
    }
    for(int kase = 1; kase <= n; ++kase) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if(opt == 0) {
            for(int i = l; i <= min(r, bl[l] * blocks); ++i) a[i] += c; update(bl[l]);
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * blocks + 1; i <= r; ++i) a[i] += c; update(bl[r]);
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) add[i] += c;
        }else {
            int ans = -1;
            for(int i = l; i <= min(r, bl[l] * blocks); ++i) if(a[i] + add[bl[i]] < c) ans = max(ans, a[i] + add[bl[i]]);
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * blocks + 1; i <= r; ++i) if(a[i] + add[bl[i]] < c) ans = max(ans, a[i] + add[bl[i]]);
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) {
                int p = lower_bound(pre[i].begin(), pre[i].end(), c - add[i]) - pre[i].begin();
                if(p == 0) continue;
                ans = max(ans, pre[i][p - 1] + add[i]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
