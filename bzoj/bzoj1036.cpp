#include <bits/stdc++.h>
#define MAXN 300005
#define MAXM 600010
using namespace std;

struct Edge{
    int to, nxt;
}edge[MAXM];
int head[MAXN], cnt;
void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void AddEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
int tot;
int pos[MAXN], pre[MAXN], son[MAXN], num[MAXN], top[MAXN], dep[MAXN], fa[MAXN];
int data[MAXN];
void DFS1(int u, int f, int d) {
    dep[u] = d; fa[u] = f; num[u] = 1;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if(v == f) continue;
        DFS1(v, u, d + 1);
        num[u] += num[v];
        if(!son[u] || num[v] > num[son[u]]) son[u] = v;
    }
}
void DFS2(int u, int number) {
    top[u] = number;
    pos[u] = ++tot;
    pre[pos[u]] = u;
    if(!son[u]) {
        return;
    }else {
        DFS2(son[u], number);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == son[u] || v == fa[u]) continue;
            DFS2(v, v);
        }
    }
}
// SegTree
struct Node{
    int l, r, sum, mx;
}tree[4 * MAXN];
inline void PushUp(int x) {
    tree[x].sum = tree[x << 1].sum + tree[x << 1 | 1].sum;
    tree[x].mx = max(tree[x << 1].mx, tree[x << 1 | 1].mx);
}
void Build(int x, int l, int r) {
    tree[x].l = l; tree[x].r = r;
    if(l == r) {
        tree[x].sum = tree[x].mx = data[pre[l]];
    }else {
        int mid = (l + r) / 2;
        Build(x << 1, l, mid);
        Build(x << 1 | 1, mid + 1, r);
        PushUp(x);
    }
}
void Modify(int x, int p, int v) {
    int L = tree[x].l, R = tree[x].r;
    if(L == R) {
        tree[x].sum = v;
        tree[x].mx = v;
    }else {
        int mid = (L + R) / 2;
        if(p <= mid) {
            Modify(x << 1, p, v);
        }else {
            Modify(x << 1 | 1, p, v);
        }
        PushUp(x);
    }
}
int QuerySum(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    if(l <= L && R <= r) {
        return tree[x].sum;
    }else {
        int mid = (L + R) / 2, ans = 0;
        if(l <= mid) {
            ans += QuerySum(x << 1, l, r);
        }
        if(r > mid) {
            ans += QuerySum(x << 1 | 1, l, r);
        }
        return ans;
    }
}
int QueryMax(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    if(l <= L && R <= r) {
        return tree[x].mx;
    }else {
        int mid = (L + R) / 2, ans = -INT_MAX;
        if(l <= mid) {
            ans = max(ans, QueryMax(x << 1, l, r));
        }
        if(r > mid) {
            ans = max(ans, QueryMax(x << 1 | 1, l, r));
        }
        return ans;
    }
}

int SolveSum(int u, int v) {
    int fu = top[u], fv = top[v], ans = 0;
    while(fu != fv) {
        if(dep[fu] < dep[fv]) {
            swap(fu, fv);
            swap(u, v);
        }
        ans += QuerySum(1, pos[fu], pos[u]);
        u = fa[fu]; fu = top[u];
    }
    if(dep[u] > dep[v]) {
        swap(u, v);
    }
    ans += QuerySum(1, pos[u], pos[v]);
    return ans;
}
int SolveMax(int u, int v) {
    int fu = top[u], fv = top[v], ans = -INT_MAX;
    while(fu != fv) {
        if(dep[fu] < dep[fv]) {
            swap(fu, fv);
            swap(u, v);
        }
        ans = max(ans, QueryMax(1, pos[fu], pos[u]));
        u = fa[fu]; fu = top[u];
    }
    if(dep[u] > dep[v]) {
        swap(u, v);
    }
    ans = max(ans, QueryMax(1, pos[u], pos[v]));
    return ans;
}
int n, u, v, q;
char str[100];
int main() {
    Init();
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        AddEdge(u, v); AddEdge(v, u);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &data[i]);
    }
    DFS1(1, 0, 1);
    DFS2(1, 1);
    Build(1, 1, n);
    scanf("%d", &q);
    while(q--) {
        scanf("%s%d%d", str, &u, &v);
        if(str[0] == 'C') {
            data[u] = v;
            Modify(1, pos[u], v);
        }else {
            if(str[1] == 'M') {
                printf("%d\n", SolveMax(u, v));
            }else {
                printf("%d\n", SolveSum(u, v));
            }
        }
    }
    return 0;
}
