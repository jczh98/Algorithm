#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int root[MAXN * 30], ls[MAXN * 30], rs[MAXN * 30], minv[MAXN * 30], tot = 0;
inline void PushUp(int x) {
    minv[x] = min(minv[ls[x]], minv[rs[x]]);
}
int Modify(int x, int l, int r, int pos, int v) {
    int rt = tot++;
    ls[rt] = ls[x]; rs[rt] = rs[x]; minv[rt] = minv[x];
    if(l == pos && r == pos) {
        minv[rt] = v;
    }else {
        int mid = (l + r) / 2;
        if(pos <= mid) ls[rt] = Modify(ls[x], l, mid, pos, v);
        else rs[rt] = Modify(rs[x], mid + 1, r, pos, v);
        PushUp(rt);
    }
    return rt;
}
int Query(int x, int l, int r, int v) {
    if(l == r) return l;
    else {
        int mid = (l + r) / 2;
        if(minv[ls[x]] < v) return Query(ls[x], l, mid, v);
        else return Query(rs[x], mid + 1, r, v);
    }
}

int n, C[MAXN], A[MAXN], sg[MAXN], mx = 100005, ans = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &C[i], &A[i]);
    }
    sg[1] = 0;
    root[1] = Modify(root[0], 0, mx, sg[1], 1);
    for(int i = 2; i <= n; i++) {
        int L = max(i - C[i - 1], 1), R = i - 1;
        sg[i] = Query(root[R], 0, mx, L);
        root[i] = Modify(root[i - 1], 0, mx, sg[i], i);
    }
    for(int i = 2; i <= n; i++) {
        if(A[i - 1] & 1) ans ^= sg[i];
    }
    if(ans) printf("First\n");
    else printf("Second\n");
    return 0;
}

