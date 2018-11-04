#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int b[N];
ll lazy[N<<2], Min[N<<2], sum[N<<2];
void build(int x, int l, int r) {
    if(l == r) {
        lazy[x] = 0;
        Min[x] = 1LL * b[l]; sum[x] = 0; return;
    }
    int mid = (l + r) / 2;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
    //sum[x] = sum[x << 1] + sum[x << 1 | 1];
    sum[x] = lazy[x] = 0;
    Min[x] = min(Min[x << 1], Min[x << 1 | 1]);
}
void pushdown(int x) {
    if(lazy[x]) {
        Min[x << 1] -= lazy[x];
        Min[x << 1 | 1] -= lazy[x];
        lazy[x << 1] += lazy[x];
        lazy[x << 1 | 1] += lazy[x];
        lazy[x] = 0;
    }
}
void update(int x, int ql, int qr, int l, int r) {
    if(ql <= l && r <= qr) {
        if(Min[x] > 1) {
            Min[x] -= 1; lazy[x] += 1; return;
        } 
        if(l == r) {
            Min[x] = b[l]; lazy[x] = 0; sum[x] += 1; return;
        }
    }
    int mid = (l + r) / 2;
    pushdown(x);
    if(ql <= mid) update(x << 1, ql, qr, l, mid);
    if(qr > mid) update(x << 1 | 1, ql, qr, mid + 1, r);
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
    Min[x] = min(Min[x << 1], Min[x << 1 | 1]);
}
ll query(int x, int ql, int qr, int l, int r) {
    if(ql <= l && r <= qr) {
        return sum[x];
    }
    int mid = (l + r) / 2;
    pushdown(x);
    int ans = 0;
    if(ql <= mid) ans += query(x<<1, ql, qr, l, mid);
    if(qr > mid) ans += query(x<<1|1, ql, qr, mid+1, r);
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
    Min[x] = min(Min[x << 1], Min[x << 1 | 1]);
    return ans;
}
int n, q, l, r;
char op[100];
int main() {
    while(scanf("%d%d", &n, &q) != EOF) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        build(1, 1, n);
        for(int t = 1; t <= q; ++t) {
            scanf("%s%d%d", op, &l, &r);
            if(op[0] == 'a') {
                update(1, l, r, 1, n);
            }else {
                printf("%lld\n", query(1, l, r, 1, n));
            }
        }        
    }
    return 0;
}