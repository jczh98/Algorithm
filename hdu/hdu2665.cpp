#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100001
using namespace std;
struct Node {
    int l, r, val;
}tree[20 * MAXN];
int root[MAXN], tot = 0, a[MAXN], b[MAXN];
inline void PushUp(int rt) {
    tree[rt].val = tree[tree[rt].l].val + tree[tree[rt].r].val;
}
int Build(int l, int r) {
    int rt = tot++;
    if(l == r) {
        tree[rt].val = 0;
    }else {
        int mid = (l + r) / 2;
        tree[rt].l = Build(l, mid);
        tree[rt].r = Build(mid + 1, r);
        PushUp(rt);
    }
    return rt;
}
int Update(int x, int l, int r, int pos, int v) {
    int rt = tot++;
    tree[rt] = tree[x];
    if(l == pos && pos == r) {
        tree[rt].val += v;
    }else {
        int mid = (l + r) / 2;
        if(pos <= mid) tree[rt].l = Update(tree[x].l, l, mid, pos, v);
        else tree[rt].r = Update(tree[x].r, mid + 1, r, pos, v);
        PushUp(rt);
    }
    return rt;
}
int Query(int qs, int qt, int l, int r, int kth) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    int res = tree[tree[qt].l].val - tree[tree[qs].l].val;
    if(kth <= res) return Query(tree[qs].l, tree[qt].l, l, mid, kth);
    else return Query(tree[qs].r, tree[qt].r, mid + 1, r, kth - res);
}
int t, n, m, st, ed, k;
int main() {
    scanf("%d", &t);
    while(t--) {
        tot = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        int cnt = 1;
        for(int i = 2; i <= n; i++) {
            if(b[i] != b[cnt]) {
                b[++cnt] = b[i];
            }
        }
        root[0] = Build(1, cnt);
        for(int i = 1; i <= n; i++) {
            int p = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
            root[i] = Update(root[i-1], 1, cnt, p, 1);
        }
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &st, &ed, &k);
            int id = Query(root[st - 1], root[ed], 1, cnt, k);
            printf("%d\n", b[id]);
        }
    }
    return 0;
}

