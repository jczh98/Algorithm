#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100010
vector<int> G[maxn], pos[maxn], large;
int dfn[maxn];
int L[maxn], R[maxn];
int tim;
int n, m;
int Limit = 1000;
ll s[maxn], C[maxn];
void dfs(int now, int deep) {
    int nex;
    L[now] = ++tim;
    pos[deep].push_back(L[now]);
    for (int i = 0, sz = G[now].size(); i < sz; i++) {
        nex = G[now][i];
        dfn[nex] = dfn[now] + 1;
        dfs(nex, deep + 1);
    }
    R[now] = tim;
    return;
}
int lowbit(int x) { return x & -x; }
void add(int x, int d) {
    while (x <= n) C[x] += d, x += lowbit(x);
    return;
}
ll sum(int x) {
    ll ret = 0;
    while (x > 0) ret += C[x], x -= lowbit(x);
    return ret;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= n; i++) pos[i].clear();
    large.clear();
    for (int i = 1; i <= n; i++) G[i].clear();
    int u, v;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    memset(dfn, 0, sizeof(dfn));
    tim = 0;
    dfs(1, 0);
    for (int i = 0; i <= n; i++)
        if (pos[i].size() > Limit) large.push_back(i);
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, y;
            scanf("%d %d", &l, &y);
            if (pos[l].size() <= Limit)
                for (int i = 0, sz = pos[l].size(); i < sz; i++)
                    add(pos[l][i], y);
            else s[l] += y;
        } else {
            int x;
            scanf("%d", &x);
            int l = L[x], r = R[x];        
            ll ans = sum(r) - sum(l - 1);
            for (int i = 0, sz = large.size(); i < sz; i++)
                ans += (upper_bound(pos[large[i]].begin(),
                                    pos[large[i]].end(), r) -
                        lower_bound(pos[large[i]].begin(),
                                    pos[large[i]].end(), l)) *
                        s[large[i]];
            printf("%lld\n", ans);
        }
    }
    return 0;
}