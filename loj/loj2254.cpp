#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, q, a[50005], len, bl[50005], l1, r1, l2, r2, cntq = 0, cntl[50005], cntr[50005];
LL ans[50005];
struct node {
    int l, r, id, flag;
    node(){}
    node(int l, int r, int flag, int id) :l(l), r(r), flag(flag), id(id){}
}Q[200010];
inline bool cmp (const node & a, const node & b) {
    return bl[a.l] == bl[b.l] ? a.r < b.r : bl[a.l] < bl[b.l];
}
int main() {
    scanf("%d", &n); len = int(sqrt(n * 1.0));
    for(register int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); bl[i] = (i - 1) / len + 1;
    }
    scanf("%d", &q);
    for(register int i = 1; i <= q; ++i) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        Q[++cntq] = node(r1, r2, 1, i);
        if(l1 > 1) Q[++cntq] = node(l1 - 1, r2, -1, i);
        if(l2 > 1) Q[++cntq] = node(r1, l2 - 1, -1, i);
        if(l1 > 1 && l2 > 1) Q[++cntq] = node(l1 - 1, l2 - 1, 1, i);
    }
    for(register int i = 1; i <= cntq; ++i) if(Q[i].l > Q[i].r) swap(Q[i].l, Q[i].r);
    sort(Q + 1, Q + cntq + 1, cmp);
    int l = 1, r = 0; LL now = 0; cntl[a[l]]++;
    for(register int i = 1; i <= cntq; ++i) {
        while(l < Q[i].l) {
            l++; now += cntr[a[l]]; cntl[a[l]]++;
        }
        while(l > Q[i].l) {
            now -= cntr[a[l]]; cntl[a[l]]--; l--;
        }
        while(r < Q[i].r) {
            r++; now += cntl[a[r]]; cntr[a[r]]++;
        }  
        while(r > Q[i].r) {
            now -= cntl[a[r]]; cntr[a[r]]--; r--;
        }
        ans[Q[i].id] += Q[i].flag * now;
    }
    for(register int i = 1; i <= q; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}