#include<bits/stdc++.h>
#define MAXN 505
#define MAXM 100010
using namespace std;
typedef long long ll;
const ll inf = 1000000000000000;
struct Edge{
    ll to, nxt, cap, cost;
}edge[MAXM];
ll head[MAXN], cnt;
ll d[MAXN], last[MAXN], vis[MAXN];
ll flow, cost;
void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void AddEdge(ll u, ll v, ll cap, ll cost) {
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].cost = cost;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
void add(ll u, ll v, ll cap, ll cost) {
    AddEdge(u, v, cap, cost); AddEdge(v, u, 0, -cost);
}
bool Spfa(ll s, ll t, ll &flow, ll &cost) {
    //memset(last, -1, sizeof(last));
    //memset(d, 127, sizeof(d));
    //memset(vis, 0,sizeof(vis));
    for(ll i = 0; i < MAXN; ++i) {
        last[i] = -1; d[i] = inf; vis[i] = 0;
    }
    d[s] = 0; vis[s] = 1; last[s] = -1;
    queue<ll> que; que.push(s);
    while(!que.empty()) {
        ll u = que.front(); que.pop();
        vis[u] = 0;
        for(ll i = head[u]; ~i; i = edge[i].nxt) {
            ll v = edge[i].to;
            if(edge[i].cap && d[v] > d[u] + edge[i].cost) {
                d[v] = d[u] + edge[i].cost;
                last[v] = i;
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    if(d[t] == inf) return false;
    ll mi = inf;
    for(ll i = last[t]; ~i; i = last[edge[i ^ 1].to]) mi = min(mi, edge[i].cap);
    flow += mi;
    for(ll i = last[t]; ~i; i = last[edge[i ^ 1].to]) {
        cost += edge[i].cost * mi;
        edge[i].cap -= mi;
        edge[i ^ 1].cap += mi;
    }
    return true;
}
void MCMF(ll s, ll t) {
    flow = 0, cost = 0;
    while(Spfa(s, t, flow, cost));
}
ll n, k, t, C[MAXN][MAXN], S, T, arr[MAXN];
ll ans = inf;
int main() {
    scanf("%lld%lld%lld", &n, &k, &t);
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= k+1; ++j) {
            scanf("%lld", &C[i][j]);
        }
    }
    S = 0; T = k+1+n+1;
    for(ll i = 1;  i <= n; ++i) {
        Init();
        for(ll j = 1; j <= n; ++j) {
            add(S, k+1+j, 1, 0);
        }
        for(ll j = 1; j <= k; ++j) {
            if(j == t) add(j, T, i, -inf);
            else add(j, T, i - 1, 0);
        }
        add(k+1, T, inf, 0);
        for(ll j = 1; j <= n; ++j) {
            for(ll l = 1; l <= k+1; ++l) {
                add(k+1+j, l, 1, C[j][l]);
            }
        }
        MCMF(S, T);
        cost += i*inf; cost %= inf;
        if(cost < ans) {
            ans = cost;
            for(ll i = 1; i <= n; ++i) {
                for(ll j = head[k+i+1]; ~j; j = edge[j].nxt) {
                    if(edge[j].to == S) continue;
                    if(edge[j].cap == 0) {
                        arr[i] = edge[j].to; break;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    for(ll i = 1; i <= n; ++i) {
        printf("%lld%c", arr[i], i == n ? '\n' : ' ');
    }
    return 0;
}

