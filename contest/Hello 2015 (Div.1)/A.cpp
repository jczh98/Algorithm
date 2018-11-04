#include <bits/stdc++.h>
#define MAXN 20005
using namespace std;
int b[MAXN];
struct SegTree {
    int lch[MAXN * 4], rch[MAXN * 4], Max[MAXN * 4];
    void pushup(int x) {
        Max[x] = max(Max[x << 1], Max[x << 1 | 1]);
    }
    void build(int x, int l, int r) {
        lch[x] = l; rch[x] = r;
        if(l == r) {
            Max[x] = b[x]; return;
        }
        int mid = (l + r) >> 1;
        build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
        pushup(x);
    }
    int query(int x, int l, int r) {
        if(l <= lch[x] && rch[x] <= r) {
            return Max[x];
        }
        int mid = (lch[x] + rch[x]) >> 1;
        if(r <= mid) return query(x << 1, l, r);
        else if(l > mid) return query(x << 1 | 1, l, r);
        else return max(query(x << 1, l, mid), query(x << 1 | 1, mid + 1, r));
    }
}seg[20];
int n, m, a[MAXN], x;
int main() {
    scanf("%d%d", &)
}