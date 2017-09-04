#include <bits/stdc++.h>
#define MAXN 20005
#define MAXM 100005
#define inf 0x3f3f3f3f
using namespace std;

int n, m, s;
int head[MAXN], cnt;
int fa[MAXN];
int ancient[MAXN][20], minw[MAXN][20], dep[MAXN];

struct Node {
    int u, v, w;
    bool operator<(const Node &rhs) const {
        return w > rhs.w;
    }
} ori_edge[MAXM];

struct Edge {
    int to, nxt, w;
} edge[MAXM * 2];

int Find(int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void AddEdge(int u, int v, int w) {
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}

void Add(int u, int v, int w) {
    AddEdge(u, v, w);
    AddEdge(v, u, w);
}

void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
    for (int i = 1; i <= n; i++) fa[i] = i;
}

void Kruskal() {
    sort(ori_edge + 1, ori_edge + m + 1);
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int f1 = Find(ori_edge[i].u);
        int f2 = Find(ori_edge[i].v);
        if (f1 != f2) {
            fa[f1] = f2;
            Add(ori_edge[i].u, ori_edge[i].v, ori_edge[i].w);
            cnt++;
            if (cnt == n - 1) break;
        }
    }
}

void Dfs(int u, int f, int d) {
    fa[u] = f;
    dep[u] = d;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == f) continue;
        minw[v][0] = edge[i].w;
        Dfs(v, u, d + 1);
    }
}

void Pre() {
    memset(ancient, -1, sizeof(ancient));
    for (int i = 1; i <= n; i++) {
        ancient[i][0] = fa[i];
    }
    minw[1][0] = inf;
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (~ancient[i][j - 1]) {
                int f = ancient[i][j - 1];
                ancient[i][j] = ancient[f][j - 1];
                minw[i][j] = min(minw[i][j - 1], minw[f][j - 1]);
            }
        }
    }
}

int Query(int p, int q) {
    if (dep[p] < dep[q]) swap(p, q);
    int k = 0;
    while ((1 << k) < dep[p]) k++;
    int ans = inf;
    for (int i = k; i >= 0; i--) {
        if (~ancient[p][i] && dep[ancient[p][i]] >= dep[q]) {
            ans = min(ans, minw[p][i]), p = ancient[p][i];
        }

    }

    if (p == q) return ans;
    for (int i = k; i >= 0; i--) {
        if (~ancient[p][i] && ancient[p][i] != ancient[q][i]) {
            ans = min(ans, minw[p][i]);
            p = ancient[p][i];
            ans = min(ans, minw[q][i]);
            q = ancient[q][i];
        }
    }

    if (p != q) {
        ans = min(ans, minw[p][0]);
        ans = min(ans, minw[q][0]);
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    Init();
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &ori_edge[i].u, &ori_edge[i].v, &ori_edge[i].w);
    }
    Kruskal();
    Dfs(1, -1, 1);
    Pre();
    for (int i = 1; i <= s; i++) {
        int l, h;
        scanf("%d%d", &l, &h);
        printf("%d\n", Query(l, h));
    }
    return 0;
}


