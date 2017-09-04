#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long LL;
int a[MAXN];
int root[MAXN * 30], ls[MAXN * 30], rs[MAXN * 30], tot;
LL sum[MAXN * 30], lazy[MAXN * 30];
inline void PushUp(int l, int r, int x) {
    sum[x] = sum[ls[x]] + sum[rs[x]] + 1LL * (r - l + 1) * lazy[x];
}
int Build(int l, int r) {
    int rt = tot++;
    if(l == r) {
        sum[rt] = a[l];
        lazy[rt] = 0;
    }else {
        int mid = (l + r) / 2;
        ls[rt] = Build(l, mid);
        rs[rt] = Build(mid + 1, r);
        PushUp(l, r, rt);
    }
    return rt;
}
int Update(int x, int L, int R, int l, int r, int v) {
    int rt = tot++;
    ls[rt] = ls[x]; rs[rt] = rs[x]; sum[rt] = sum[x]; lazy[rt] = lazy[x];
    sum[rt] += 1LL * (r - l + 1)*v;
    if(L == l && r == R) {
        lazy[rt] += 1LL * v;
    }else {
        int mid = (L + R) / 2;
        if(r <= mid) {
            ls[rt] = Update(ls[x], L, mid, l, r, v);
        }else if(l > mid) {
            rs[rt] = Update(rs[x], mid + 1, R, l, r, v);
        }else {
            ls[rt] = Update(ls[x], L, mid, l, mid, v);
            rs[rt] = Update(rs[x], mid + 1, R, mid + 1, r, v);
        }
    }
    return rt;
}
LL Query(int x, int L, int R, int l, int r) {
    LL res = 0;
    if(L == l && r == R) {
        return sum[x];
    }else {
        int mid = (L + R) / 2;
        res += 1LL * (r - l + 1) * lazy[x];
        if(r <= mid) {
            return res + Query(ls[x], L, mid, l, r);
        }else if(l > mid) {
            return res + Query(rs[x], mid + 1, R, l, r);
        }else {
            return res + Query(ls[x], L, mid, l, mid) + Query(rs[x], mid + 1, R, mid + 1, r);
        }
    }
}
int n, m, now;
int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        tot = 0; now = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        root[now] = Build(1, n);
        for(int i = 1; i <= m; i++) {
            char str[10];
            scanf("%s",str);
            if(str[0] == 'C') {
                int l, r, c;
                scanf("%d%d%d", &l, &r, &c);
                root[now + 1] = Update(root[now], 1, n, l, r, c);
                now++;
            }else if(str[0] == 'Q') {
                int l, r;
                scanf("%d%d", &l, &r);
                printf("%lld\n", Query(root[now], 1, n, l, r));
            }else if(str[0] == 'H') {
                int l, r, v;
                scanf("%d%d%d", &l, &r, &v);
                printf("%lld\n", Query(root[v], 1, n, l, r));
            }else if(str[0] == 'B') {
                int v;
                scanf("%d", &v);
                now = v;
            }
        }
        //printf("\n");
    }
    return 0;
}

