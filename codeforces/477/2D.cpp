#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, L[1000005], a, h, tmp, lch, rch, last;
long long ans = 0;
vector<int> d[1000005];
vector<LL> pre[1000005];
LL query(int x, int h) {
    if(h <= 0) return 0;
    int p = upper_bound(d[x].begin(), d[x].end(), h) - d[x].begin();
    return 1LL * p * h - 1LL * pre[x][p - 1];
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 2; i <= n; ++i) scanf("%d", &L[i]);
    for(int i = n; i >= 1; --i) {
        d[i].push_back(0);
        lch = i << 1; rch = i << 1 | 1;
        if(lch <= n) {
            for(int j = 0; j < d[lch].size(); ++j) d[i].push_back(d[lch][j] + L[lch]);
        }
        if(rch <= n) {
            for(int j = 0; j < d[rch].size(); ++j) d[i].push_back(d[rch][j] + L[rch]);
        }
        sort(d[i].begin(), d[i].end());
        pre[i].resize(d[i].size());
        for(int j = 1; j < pre[i].size(); ++j) {
            pre[i][j] = pre[i][j - 1] + d[i][j];
        }
    }
    for(; m; --m) {
        scanf("%d%d", &a, &h); ans = 0;
        tmp = a; last = 0;
        while(tmp) {
            if(h < 0) break; ans += h;
            lch = tmp << 1; rch = tmp << 1 | 1;
            if(lch <= n && lch != last) {
                ans += query(lch, h - L[lch]);
            }
            if(rch <= n && rch != last) {
                ans += query(rch, h - L[rch]);
            }
            h -= L[tmp]; last = tmp; tmp >>= 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}