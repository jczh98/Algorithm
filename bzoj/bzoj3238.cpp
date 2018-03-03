#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1001000;
int trans[N][30], pa[N], maxlen[N], sz, root, last, Right[N];
inline void init_sam() {
    memset(trans, 0, sizeof(trans));
    root = last = sz = 1;
}
inline void extend(int c, int x) {
    int p = last, np = ++sz; last = np; maxlen[np] = x; Right[np] = 1;
    for(; p && !trans[p][c]; p = pa[p]) trans[p][c] = np;
    if(!p) {pa[np] = root; return;}
    int q = trans[p][c];
    if(maxlen[q] == maxlen[p] + 1) {
        pa[np] = q;
    }else {
        int nq = ++sz;
        memcpy(trans[nq], trans[q], sizeof(trans[q]));
        pa[nq] = pa[q]; maxlen[nq] = maxlen[p] + 1; pa[q] = pa[np] = nq;
        for(; trans[p][c] == q; p = pa[p]) trans[p][c] = nq;
    }
}
inline void build(char *s) {
    int len = strlen(s);
    for(int i = 0; i < len; ++i) extend(s[i] - 'a', i + 1);
}
int cnt, head[N], nxt[N], to[N];
inline void init_edge() {cnt = 0; memset(head, -1, sizeof(head));}
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
LL ans = 0;
int dfs(int u) {
    for(int i = head[u]; ~i; i = nxt[i]) Right[u] += dfs(to[i]);
    ans -= 1LL * Right[u] * (Right[u] - 1) * (maxlen[u] - maxlen[pa[u]]);
    return Right[u];
}
inline void get() {
    init_edge();
    for(int i = 2; i <= sz; ++i) add(pa[i], i);
    dfs(root);
}
char str[N];
int main() {
    scanf("%s", str);
    int len = strlen(str);
    reverse(str, str + len);
    init_sam();
    build(str);
    ans = 1LL * len * (len - 1) * (len + 1) / 2;
    get();
    cout << ans << endl;
    return 0;
}