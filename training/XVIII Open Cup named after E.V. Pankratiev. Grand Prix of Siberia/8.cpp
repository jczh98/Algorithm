#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 129000;
int T[N], cnt[N*50], tot = 0, lch[N*50], rch[N*50];
ll sum[N*50], suma[N*50];
int n, m, a[N], d[N], b[N];
int insert(int rt, int l, int r, int p, int val) {
    int nrt = ++tot;
    cnt[nrt] = cnt[rt] + 1; sum[nrt] = sum[rt] + 1LL * val;
    if(l == r) return nrt;
    int mid = (l+r)>>1;
    if(p <= mid) {
        lch[nrt] = insert(lch[rt], l, mid, p, val); rch[nrt] = rch[rt];
    } else {
        rch[nrt] = insert(rch[rt], mid+1, r, p, val); lch[nrt] = lch[rt];
    }
    return nrt;
}
inline ll kth(int rt, int x, int y){
    if (!rt) return 0;
    int a = 1, b = n;
    ll ans = 0;
    while (a < b) {
        int mid = (a + b) >> 1;
        int t = cnt[lch[x]] - cnt[lch[y]];
        if (t >= rt) {
            b = mid;
            x = lch[x];
            y = lch[y];
        } else {
            rt -= t;
            ans += sum[lch[x]] - sum[lch[y]];
            a = mid + 1;
            x = rch[x];
            y = rch[y];
        }
    }
    if (rt) ans += (sum[x] - sum[y]) / (cnt[x] - cnt[y]) * rt;
    return ans;
}
ll query(int x, int y, int l, int r) {
    return kth(r, x, y) - kth(l - 1, x, y);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); suma[i] = suma[i-1] + 1LL * a[i];
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
    }
    for(int i = 1; i <= n; ++i) b[i] = d[i] - a[i];
    sort(b+1, b+1+n);
    for(int i = 1; i <= n; ++i) {
        T[i] = insert(T[i-1], 1, n, (lower_bound(b+1,b+1+n,d[i]-a[i])-b), d[i]-a[i]);
    }
    scanf("%d", &m);
    int l, r, len;
    ll ans;
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        ans = (suma[r] - suma[l - 1]) * 2;
        len = (r-l+1)/3;
        ans += query(T[r], T[l-1], len*2+1, len*3)*2;
        ans += query(T[r], T[l-1], len+1, len*2);
        printf("%f\n",ans*1.0/2);
    }
    return 0;
}
