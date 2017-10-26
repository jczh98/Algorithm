#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXM = 500005;
const int inf = 0x7f7f7f7f;
int cmp_dim;
struct Node {
    int D[2], Max[2], Min[2], l, r;
    int & operator [] (int x) {return D[x];}
    bool operator < (const Node & rhs) const {return D[cmp_dim] < rhs.D[cmp_dim];}
}kdt[MAXN + MAXM], data[MAXN];
int root = 0;
inline void MakeNode(int x, int x1, int y1) {
    kdt[x][0] = x1; kdt[x][1] = y1;
    for(int i = 0; i <= 1; ++i) kdt[x].Max[i] = kdt[x].Min[i] = kdt[x][i];
}
void Insert(int x, int x1, int y1) {
    MakeNode(x, x1, y1);
    if(!root) {
        root = x; return;
    }
    int now = root, dim = 0;
    while(true) {
        kdt[now].Min[0] = min(kdt[now].Min[0], kdt[x].Min[0]);
        kdt[now].Max[0] = max(kdt[now].Max[0], kdt[x].Max[0]);
        kdt[now].Min[1] = min(kdt[now].Min[1], kdt[x].Min[1]);
        kdt[now].Max[1] = max(kdt[now].Max[1], kdt[x].Max[1]);
        if(kdt[x][dim] <= kdt[now][dim]) {
            if(kdt[now].l) now = kdt[now].l; else {kdt[now].l = x; break;}
        }else {
            if(kdt[now].r) now = kdt[now].r; else {kdt[now].r = x; break;}
        }
        dim ^= 1;
    }
}
inline void PushUp(int x) {
    int l = kdt[x].l, r = kdt[x].r;
    for(int i = 0; i <= 1; ++i) {
        if(l) {
            kdt[x].Max[i] = max(kdt[x].Max[i], kdt[l].Max[i]);
            kdt[x].Min[i] = min(kdt[x].Min[i], kdt[l].Min[i]);
        }
        if(r) {
            kdt[x].Min[i] = min(kdt[x].Min[i], kdt[r].Min[i]);
            kdt[x].Max[i] = max(kdt[x].Max[i], kdt[r].Max[i]);
        }
    }
}
int Build(int l, int r, int now) {
    if(l > r) return 0;
    int mid = (l + r) >> 1;
    cmp_dim = now;
    nth_element(data + l, data + mid, data + r + 1);
    kdt[mid] = data[mid];
    kdt[mid].l = Build(l, mid - 1, now ^ 1);
    kdt[mid].r = Build(mid + 1, r, now ^ 1);
    PushUp(mid);
    return mid;
}
int dis(Node a, Node b) {return abs(a[0] - b[0]) + abs(a[1] - b[1]);}
int Get(int x, Node p){
    int tmp = 0;
    for (int i = 0; i <= 1; i++)
        tmp += max(0, kdt[x].Min[i] - p[i]);
    for (int i = 0; i < 2; i++)
        tmp += max(0, p[i] - kdt[x].Max[i]);
    return tmp;
}
int ans;
int Query(int rt, Node p) {
    int d = dis(kdt[rt], p), dl = inf, dr = inf;
    ans = min(ans, d);
    if(kdt[rt].l) dl = Get(kdt[rt].l, p);
    if(kdt[rt].r) dr = Get(kdt[rt].r, p);
    if(dl < dr) {
        if(dl < ans) Query(kdt[rt].l, p);
        if(dr < ans) Query(kdt[rt].r, p);
    }else {
        if(dr < ans) Query(kdt[rt].r, p);
        if(dl < ans) Query(kdt[rt].l, p);
    }
}
int n, m, x, y, opt;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        data[i][0] = data[i].Min[0] = data[i].Max[0] = x;
        data[i][1] = data[i].Min[1] = data[i].Max[1] = y;
    }
    root = Build(1, n, 0);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &opt, &x, &y);
        if(opt == 1) {
            Insert(++n, x, y);
        }else {
            ans = inf;
            Node p; p[0] = x; p[1] = y;
            Query(root, p);
            printf("%d\n", ans);
        }
    }
    return 0;
}