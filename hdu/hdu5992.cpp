#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int Dimension = 2;
const int MAXN = 200005;
const int MAXT = MAXN << 2;
int cmp_dim;
struct Node {
    int D[Dimension], c, id;
    bool operator < (const Node & rhs) const {return D[cmp_dim] < rhs.D[cmp_dim];}
}kdt[MAXT], data[MAXN], p;
typedef pair<LL, Node> pln;
int son[MAXT], Min[MAXT];
int ans, T, n, m, a, b, c;
priority_queue<pln> pq;
inline LL Dis(Node a, Node b) {return 1LL * (a.D[0] - b.D[0]) * (a.D[0] - b.D[0]) + 1LL * (a.D[1] - b.D[1]) * (a.D[1] - b.D[1]);}
inline LL Sqr(int x) {return 1LL * x * x;}
void Build(int x, int l, int r, int now) {
    if(l > r) return;
    son[x] = 1; son[x << 1] = son[x << 1 | 1] = -1;
    int mid = (l + r) >> 1;
    cmp_dim = now;
    nth_element(data + l, data + mid, data + r + 1);
    kdt[x] = data[mid];
    Min[x] = data[mid].c;
    Build(x << 1, l, mid - 1, (now + 1) % Dimension);
    Build(x << 1 | 1, mid + 1, r, (now + 1) % Dimension);
    Min[x] = min(Min[x], min(Min[x << 1], Min[x << 1 | 1]));
}
void Query(int x, int now, int m, Node p) {
    if(son[x] == -1) return;
    pln cur(0, kdt[x]);
    cur.first = Dis(p, kdt[x]);
    int ls = x << 1, rs = x << 1 | 1, flag = 0;
    if(p.D[now] >= kdt[x].D[now]) swap(ls, rs);
    if(p.c < kdt[x].c) cur.first = LONG_LONG_MAX;
    if(~son[ls] && Min[ls] <= p.c) Query(ls, (now + 1) % Dimension, m, p);
    if(pq.size() < m) {
        pq.push(cur); flag = 1;
    }else {
        if(cur.first < pq.top().first) pq.pop(), pq.push(cur);
        else if(cur.first == pq.top().first && cur.second.id < pq.top().second.id) pq.pop(), pq.push(cur);
        if(Sqr(p.D[now] - kdt[x].D[now]) <= pq.top().first) flag = 1;
    }
    if(~son[rs] && flag && Min[rs] <= p.c) Query(rs, (now + 1) % Dimension, m, p);
}
int main() {
    scanf("%d", &T);
    for(; T; --T) {
        memset(son, 0, sizeof(son));
        memset(Min, 127, sizeof(Min));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &data[i].D[0], &data[i].D[1], &data[i].c);
            data[i].id = i;
        }
        Build(1, 1, n, 0);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &p.D[0], &p.D[1], &p.c);
            while(!pq.empty()) pq.pop();
            Query(1, 0, 1, p);
            printf("%d %d %d\n", pq.top().second.D[0], pq.top().second.D[1], pq.top().second.c);
        }
    }
    return 0;
}