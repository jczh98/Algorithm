#include <bits/stdc++.h>
#define MAXN 10005
#define MAXE 100005
using namespace std;
int head[MAXN], tot1, tot2;
struct Edge {
    int u, v, next;
} e1[MAXE], e2[MAXN];
void addEdge(int u, int v, Edge *edge, int &tol) {
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}
int n, m;
int low[MAXN], dfn[MAXN], Stack[MAXN], belong[MAXN], num[MAXN];
bool instack[MAXN];
int scc, top, idx;
void Tarjan(int u) {
    int v;
    low[u] = dfn[u] = ++idx;
    Stack[top++] = u;
    instack[u] = true;
    for (int i = head[u]; i != -1; i = e1[i].next) {
        v = e1[i].v;
        if (!dfn[v]) {
            Tarjan(v);
            if (low[u] > low[v]) low[u] = low[v];
        } else if (instack[v] && low[u] > dfn[v])
            low[u] = dfn[v];
    }
    if (low[u] == dfn[u]) {
        ++scc;
        do {
            v = Stack[--top];
            instack[v] = false;
            belong[v] = scc;
            num[scc]++;
        } while (u != v);
    }
}
int inde[MAXN], outde[MAXN];
void solve() {
    memset(dfn, 0, sizeof(dfn));
    memset(instack, false, sizeof(instack));
    memset(num, 0, sizeof(num));
    scc = top = idx = 0;
    for (int i = 1; i <= n; ++i)
        if (!dfn[i]) Tarjan(i);
    tot2 = 0;
    memset(head, -1, sizeof(head));
    memset(inde, 0, sizeof(inde));
    memset(outde, 0, sizeof(outde));
    int u, v;
    for (int i = 0; i < m; ++i) {
        u = belong[e1[i].u];
        v = belong[e1[i].v];
        if (u != v) {
            addEdge(u, v, e2, tot2);
            inde[v]++;
            outde[u]++;
        }
    }
    int a = 0, b = 0;
    for (int i = 1; i <= scc; ++i) {
        if (!inde[i]) a++;
        if (!outde[i]) b++;
    }
    if (scc == 1)printf("0\n");
    else
        printf("%d\n", max(a, b));
}
int t;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        tot1 = 0;
        memset(head, -1, sizeof(head));
        int u, v;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addEdge(u, v, e1, tot1);
        }
        solve();
    }
    return 0;
}