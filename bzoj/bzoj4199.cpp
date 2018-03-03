#include <bits/stdc++.h>
#define inf (LL)1000000000000000001
using namespace std;
typedef long long LL;
const int N = 1001000;
int ch[N][30], pa[N], maxlen[N], sz, last, Right[N], mark[N], val[N];
inline void init_sam() {
    memset(ch, 0, sizeof(ch));
    last = sz = 1;
}
inline void extend(int c, int x) {
    int p = last, np = ++sz; last = np; maxlen[np] = maxlen[p] + 1; mark[np] = 1; val[np] = x;
    while(p && !ch[p][c]) ch[p][c] = np, p = pa[p];
    if(!p) {pa[np] = 1; return;}
    int q = ch[p][c];
    if(maxlen[q] == maxlen[p] + 1) {
        pa[np] = q;
    }else {
        int nq = ++sz;
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        pa[nq] = pa[q]; maxlen[nq] = maxlen[p] + 1; pa[q] = pa[np] = nq;
        while(ch[p][c] == q) ch[p][c] = nq, p = pa[p];
    }
}
int cnt, head[N], nxt[N], to[N];
inline void init_edge() {cnt = 0; memset(head, -1, sizeof(head));}
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
int n, a[N];
LL ans1[N], ans2[N], Max[N], Min[N];
char str[N];
void dfs(int u) {
    Right[u] = 0; Max[u] = -inf; Min[u] = inf;
    if(mark[u]) Right[u] = 1, Max[u] = Min[u] = val[u];
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i]; dfs(v);
        if(Max[u] != -inf && Max[v] != -inf && Min[u] != inf && Min[v] != inf) {
            ans2[maxlen[u]] = max(ans2[maxlen[u]], max(Max[u] * Max[v], Min[u] * Min[v]));
        }    
        Max[u] = max(Max[u], Max[v]); Min[u] = min(Min[u], Min[v]);
        ans1[maxlen[u]] += 1LL * Right[u] * Right[v];
        Right[u] += Right[v];
    }
}
int main() {
    init_sam();
    init_edge();
    scanf("%d", &n);
    scanf("%s", str + 1);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = n; i >= 1; --i) extend(str[i] - 'a', a[i]);
    for(int i = 2; i <= sz; ++i) add(pa[i], i);
    for(int i = 0; i <= n; ++i) ans2[i] = -inf;
    dfs(1);
    for(int i = n - 1; i >= 0; --i) ans1[i] += ans1[i + 1], ans2[i] = max(ans2[i], ans2[i + 1]);
    for(int i = 0; i < n; ++i) {
        if(ans1[i])printf("%lld %lld\n", ans1[i], ans2[i]);
        else printf("0 0\n");
    }
    return 0;
}