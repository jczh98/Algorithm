#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node {
    int x, y;
    bool operator < (const node & rhs) const {return x == rhs.x ? y > rhs.y : x < rhs.x;}
}a[1000005];
int n, k, q[1000005], o;
LL sum[1000005], f[1000005], g[1000005];
void solve(int l, int r, int dl, int dr) {
    if(l > r) return;
    int m = (l + r) / 2, dm = dl; g[m] = 0;
    for(int i = dl; i <= dr && i <= m; ++i) {
        LL t = f[q[i]];
        if(m - i <= o) t += sum[m - i];
        if(t > g[m]) g[m] = t, dm = i;
    }
    solve(l, m - 1, dl, dm); solve(m + 1, r, dm, dr);
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + 1 + n);
    int j;
    for(int i = 1; i <= n; i = j) {
        if(a[i].x > k) break;
        for(j = i; j <= n && a[i].x == a[j].x; ++j) sum[j - i + 1] = sum[j - i] + a[j].y;
        o = j - i;
        for(int l = 0; l < a[i].x; ++l) {
            int x, y;
            for(x = l, y = 0; x <= k; x += a[i].x) q[++y] = x;
            solve(1, y, 1, y);
            for(x = 1; x <= y; ++x) f[q[x]] = g[x];
        }
    }
    for(int i = 1; i <= k; ++i) {
        printf("%lld%c", f[i], i == k ? '\n' : ' ');
    }
    return 0;
}