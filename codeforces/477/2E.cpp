#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long LL;
const int N = 1000005;
int n, m, x, y, w, s;
int head[N], nxt[N], to[N], val[N], cnt;
inline void init(){memset(head, -1, sizeof(head)); cnt = 0;}
inline void add(int u, int v, int w) {to[cnt] = v, val[cnt] = w, nxt[cnt] = head[u], head[u] = cnt++;}
int head2[N], nxt2[N], to2[N], cnt2; LL val2[N];
inline void init2() {memset(head2, -1, sizeof(head)); cnt2 = 0;}
inline void add2(int u, int v, LL w) {to2[cnt2] = v, val2[cnt2] = w, nxt2[cnt2] = head2[u], head2[u] = cnt2++;}
int dfs_ind = 1, dfn[N], low[N], sccno[N], scc_cnt = 0;
LL w_[N];
stack<int> st;
void tarjan(int u) {
    dfn[u] = low[u] = dfs_ind++;
    st.push(u);
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {tarjan(v); low[u] = min(low[u], low[v]);}
        else if(!sccno[v]) {low[u] = min(low[u], dfn[v]);}
    }
    if(dfn[u] == low[u]) {
        scc_cnt++;
        while(1) {
            int x = st.top(); st.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}
inline LL cal(LL x) {
    LL n = sqrt(2.0 * x + 0.25) - 0.5;
    return (n + 1) * x - (n + 1) * (n + 2) * n / 6;
}
void DAG() {
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(sccno,0,sizeof(sccno));
    memset(w_,0,sizeof(w_));
    init2();
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= n; ++i) {
        for(int j = head[i]; ~j; j = nxt[j]) {
            int v = to[j];
            if(sccno[i] != sccno[v]) {
                add2(sccno[i], sccno[v], 1LL * val[j]);
            }else w_[sccno[i]] += cal(val[j]);
        }
    }
}
LL dp[N];
void dfs(int u) {
    if(~dp[u]) return;
    dp[u] = w_[u];
    for(int i = head2[u]; ~i; i = nxt2[i]) {
        dfs(to2[i]);
        dp[u] = max(dp[u], w_[u] + dp[to2[i]] + val2[i]);
    }
}
int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        add(x, y, w);
    }
    scanf("%d", &s);
    DAG();
    memset(dp, -1, sizeof(dp));
    dfs(sccno[s]);
    cout << dp[sccno[s]] << endl;
    return 0;
}