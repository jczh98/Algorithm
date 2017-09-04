#include <bits/stdc++.h>
#define inf 10000000
#define MN 100010
using namespace std;
int n, m, t, indeg[MN];
struct Node {
    int l, r, minv, lazy;
    void update(int v) {
        minv += v;
        lazy += v;
    }
}tree[4 * MN];

void PushUp(int x) {
    tree[x].minv = min(tree[x<<1].minv, tree[x<<1|1].minv);
}

void PushDown(int x) {
    int lazyv = tree[x].lazy;
    if(lazyv) {
        tree[x<<1].update(lazyv);
        tree[x<<1|1].update(lazyv);
        tree[x].lazy = 0;
    }
}

void Build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = 0;
    if(l == r) tree[x].minv = indeg[l];
    else {
        int mid = (l + r) / 2;
        Build(x<<1, l, mid);
        Build(x<<1|1, mid + 1, r);
        PushUp(x);
    }
}
void Update(int x, int l, int r, int v) {
    int L = tree[x].l, R = tree[x].r;
    if(l <= L && R <= r) tree[x].update(v);
    else {
        int mid = (L + R) / 2;
        PushDown(x);
        if(l <= mid) Update(x<<1, l, r, v);
        if(mid < r) Update(x<<1|1, l, r, v);
        PushUp(x);
    }
}
int Query(int x,int l,int r) {
    if(l == r) return l;
    int mid = (l + r) / 2;
    PushDown(x);
    if(tree[x<<1|1].minv == 0) return Query(x<<1|1, mid + 1, r);
    else return Query(x<<1, l, mid);
}
vector<int> G[MN];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            indeg[i] = i - 1;
            G[i].clear();
        }
        for(int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d",&x, &y);
            if(x > y) swap(x, y);
            G[x].push_back(y);
            indeg[y]--;
        }
        Build(1, 1, n);
        for(int i = 1; i <= n; i++) {
            int u = Query(1, 1, n);
            Update(1, u, u, inf);
            Update(1, u + 1, n, -1);
            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                Update(1, v, v, 1);
            }
            printf("%d%c", u, i == n ? '\n' : ' ');
        }
    }
    return 0;
}

