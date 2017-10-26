#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 50005;
const int MAXT = MAXN << 2;
int n, Dimension, cmp_dim, t, m;
int son[MAXT];
struct Node {
    int D[10];
    bool operator < (const Node & rhs) const {return D[cmp_dim] < rhs.D[cmp_dim];}
}kdt[MAXT], data[MAXN], q;
typedef pair<LL, Node> pln;
inline LL Sqr(int  x) {return 1LL * x * x;}
void Build(int x, int l, int r, int now) {
    if(l > r) return;
    cmp_dim = now;
    son[x] = 1; son[x << 1] = son[x << 1 | 1] = -1;
    int mid = (l + r) >> 1;
    nth_element(data + l, data + mid, data + r + 1);
    kdt[x] = data[mid];
    Build(x << 1, l, mid - 1, (now + 1) % Dimension);
    Build(x << 1 | 1, mid + 1, r, (now + 1) % Dimension);
}
priority_queue<pln> pq;
vector<pln> ans;
void Query(int x, int now, int m, Node p) {
    if(son[x] == -1) return;
    pln cur(0, kdt[x]);
    for(int i = 0; i < Dimension; ++i) cur.first += Sqr(kdt[x].D[i] - p.D[i]);
    int ls = x << 1, rs = x << 1 | 1, flag = 0;
    if(p.D[now] >= kdt[x].D[now]) swap(ls, rs);
    if(~son[ls]) Query(ls, (now + 1) % Dimension, m, p);
    if(pq.size() < m) {
        pq.push(cur); flag = 1;
    }else {
        if(cur.first < pq.top().first) pq.pop(), pq.push(cur);
        if(Sqr(kdt[x].D[now] - p.D[now]) < pq.top().first) flag = 1;
    }
    if(~son[rs] && flag) Query(rs, (now + 1) % Dimension, m, p);
}
int main() {
    while(scanf("%d%d", &n, &Dimension) != EOF ) {
        memset(son, 0, sizeof(son));
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < Dimension; ++j) {
                scanf("%d", &data[i].D[j]);
            }
        }
        Build(1, 1, n, 0);
        scanf("%d", &t);
        for(; t; --t) {
            for(int i = 0; i < Dimension; ++i) scanf("%d", &q.D[i]);scanf("%d", &m);
            Query(1, 0, m, q);
            printf("the closest %d points are:\n", m);
            ans.clear();
            while(!pq.empty()) {
                ans.push_back(pq.top());
                pq.pop();
            }
            for(int i = ans.size() - 1; i >= 0; --i) {
                for(int j = 0; j < Dimension; ++j) {
                    printf("%d%c", ans[i].second.D[j], j == Dimension - 1 ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}