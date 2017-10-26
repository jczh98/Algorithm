#include <bits/stdc++.h>
using namespace std;
const int MAXM = 200005;
const int MAXN = 200005;
int to[MAXM], nxt[MAXM], head[MAXM], cnt, L[MAXN], R[MAXN], tot;
int n, p, t, m; char opt[100];
int tl[MAXN], tr[MAXN], sum[MAXN], val[MAXN], lazy[MAXN];
inline void Add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
void DFS(int x) {
    L[x] = ++tot;
    for(int i = head[x]; ~i; i = nxt[i]) DFS(to[i]);
    R[x] = tot;
}
void PushUp(int x) {sum[x] = sum[x << 1] + sum[x << 1 | 1];}
void PushDown(int x) {
    if(lazy[x]) {
        sum[x << 1] = tr[x << 1] - tl[x << 1] + 1 - sum[x << 1];
        sum[x << 1 | 1] = tr[x << 1 | 1] - tl[x << 1 | 1] + 1 - sum[x << 1 | 1];
        lazy[x << 1] ^= 1; lazy[x << 1 | 1] ^= 1; lazy[x] = 0;
    }
}
void Build(int x, int l, int r) {
    tl[x] = l; tr[x] = r; lazy[x] = 0;
    if(l == r) {sum[x] = val[l]; return;}
    int mid = (l + r) >> 1;
    Build(x << 1, l, mid); Build(x << 1 | 1, mid + 1, r);
    PushUp(x);
}
void Modify(int x, int l, int r) {
    if(l == tl[x] && tr[x] == r) {
        sum[x] = tr[x] - tl[x] + 1 - sum[x]; lazy[x] ^= 1; return;
    }
    int mid = (tl[x] + tr[x]) >> 1;
    PushDown(x);
    if(r <= mid) return Modify(x << 1, l, r); 
    else if(l > mid) return Modify(x << 1 | 1, l, r);
    else return Modify(x << 1, l, mid) , Modify(x << 1 | 1, mid + 1, r);
    PushUp(x);
}
int Query(int x, int l, int r) {
    if(l == tl[x] && tr[x] == r) {return sum[x];}
    int mid = (tl[x] + tr[x]) >> 1;
    PushDown(x);
    if(r <= mid) return Query(x << 1, l, r); 
    else if(l > mid) return Query(x << 1 | 1, l, r);
    else return Query(x << 1, l, mid) + Query(x << 1 | 1, mid + 1, r);
}
int main() {
    memset(head, -1, sizeof(head)); cnt = 0;
    scanf("%d", &n);
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &p); Add(p, i);
    }
    DFS(1);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &t); val[L[i]] = t;
    }
    Build(1, 1, n);
    scanf("%d", &m);
    for(; m; --m) {
        scanf("%s%d", opt, &t);
        if(opt[0] == 'p') {
            Modify(1, L[t], R[t]);
        }else {
            printf("%d\n", Query(1, L[t], R[t]));
        }
    }
    return 0;
}