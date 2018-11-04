#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100005], q[100005], M = 0, Q, cur = 0;
int ans1[100005], ans2[100005];
int Min[1000005];
void build(int rt, int l, int r) {
    Min[rt] = INT_MAX;
    if(l == r) { Min[rt] = a[l]; return;}
    int mid = (l+r)>>1;
    build(rt<<1, l, mid); build(rt<<1|1, mid+1, r);
    Min[rt] = min(Min[rt<<1], Min[rt<<1|1]);
}
void update(int rt, int l, int r, int p, int v) {
    if(l == r) {Min[rt] = v; return;}
    int mid = (l+r)>>1;
    if(p <= mid) update(rt<<1, l, mid, p, v);
    else update(rt<<1|1, mid+1, r, p, v);
    Min[rt] = min(Min[rt<<1], Min[rt<<1|1]);
}
int query(int rt, int l, int r, int v) {
    if(l == r) return l;
    int mid = (l+r)>>1;
    if(Min[rt<<1] <= v) return query(rt<<1, l, mid, v);
    if(Min[rt<<1|1] <= v) return query(rt<<1|1, mid+1, r, v);
    return -1;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, 1, n);
    scanf("%d", &Q);
    for(int i = 1; i <= Q; ++i) scanf("%d", &q[i]), M = max(M, q[i]);
    int tmp = 0;
    for(int i = 1; i <= M; ++i) {
        if(tmp < n) cur += m;
        int f;
        if(tmp < n) while(f = query(1, 1, n, cur)) {
            if(~f) {
                cur -= a[f]; tmp++;
                update(1, 1, n, f, INT_MAX);
            } else break;
        }
        ans1[i] = cur; ans2[i] = tmp;
    }
    for(int i = 1; i <= Q; ++i) printf("%d %d\n", ans2[q[i]], ans1[q[i]]);
}