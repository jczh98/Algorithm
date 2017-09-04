#include <bits/stdc++.h>
#define MAXN 30005
using namespace std;
int root[MAXN * 20], ls[MAXN * 20], rs[MAXN * 20], val[MAXN * 20], tot = 0;
inline void PushUp(int x) {
    val[x] = val[ls[x]] + val[rs[x]];
}
int Build(int l, int r) {
    int rt = tot++;
    if(l == r) {
        val[rt] = 0;
    }else {
        int mid = (l + r) / 2;
        ls[rt] = Build(l, mid);
        rs[rt] = Build(mid + 1, r);
        PushUp(rt);
    }
    return rt;
}
int Update(int x, int l, int r, int pos, int v) {
    int rt = tot++;
    val[rt] = val[x]; ls[rt] = ls[x]; rs[rt] = rs[x];
    if(l == pos && r == pos) {
        val[rt] += v;
    }else {
        int mid = (l + r) / 2;
        if(pos <= mid) ls[rt] = Update(ls[x], l, mid, pos, v);
        else rs[rt] = Update(rs[x], mid + 1, r, pos, v);
        PushUp(rt);
    }
    return rt;
}
int Query(int l, int r, int x, int pos) {
    if(l == r) return val[x];
    int mid = (l + r) / 2;
    if(pos <= mid) return val[rs[x]] + Query(l, mid, ls[x], pos);
    else return Query(mid + 1, r, rs[x], pos);
}
int n, a[MAXN], q;
map<int, int> mp;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    root[0] = Build(1, n);
    for(int i = 1; i <= n; i++) {
        if(!mp[a[i]]) {
            root[i] = Update(root[i - 1], 1, n, i, 1);
        }else {
            int t = Update(root[i - 1], 1, n, mp[a[i]], -1);
            root[i] = Update(t, 1, n, i, 1);
        }
        mp[a[i]] = i;
    }
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int a, b;
        scanf("%d%d",&a, &b);
        printf("%d\n", Query(1, n, root[b], a));
    }
    return 0;
}

