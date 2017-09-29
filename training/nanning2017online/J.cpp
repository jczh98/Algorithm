#include <bits/stdc++.h>
#define MAXN 402880
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
int n;
struct Edge{
    int to, nxt;
}edge[MAXN * 9];
int head[MAXN], cnt;
int dis[MAXN], vis[MAXN];
vector<int> a;
vector<vector<int> > node;
map<pii, int> mapping;
map<LL, int> mark_id;
int marked_id_tot = 0;
void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void AddEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
void Add(int u, int v) {
    if(mapping[make_pair(u, v)] || mapping[make_pair(v, u)]) return;
    //cout << u << " " << v << endl;
    AddEdge(u, v); AddEdge(v, u);
    mapping[make_pair(u, v)] = 1;
    mapping[make_pair(v, u)] = 1;
}
int GetId(vector<int> nd) {
    LL sum = 0;
    for(int i = 0; i < nd.size(); ++i) {
        sum *= 10;
        sum += nd[i];
    }
    if(mark_id[sum]) return mark_id[sum];
    else {
        mark_id[sum] = ++marked_id_tot;
        return mark_id[sum];
    }
}
int Dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 127, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii> > que;
    dis[s] = 0;
    que.push(make_pair(dis[s], s));
    while (!que.empty()) {
        int u = que.top().second;
        que.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                que.push(make_pair(dis[v], v));
            }
        }
    }
}
LL s, t;
int main() {
    Init();
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        a.push_back(i);
    }
    do {
/*        for(int i = 0; i < a.size(); ++i) {
            cout << a[i] << " ";
        }cout << endl;*/
        node.push_back(a);
    }while(next_permutation(a.begin(), a.end()));
    for(int i = 0; i < node.size(); ++i) {
        for(int j = 1; j < node[i].size(); ++j) {
            vector<int> tmp = node[i];
            swap(tmp[j], tmp[0]);
            Add(GetId(node[i]), GetId(tmp));
        }
    }
    for(int i = 1; i <= 5; ++i) {
        scanf("%lld%lld", &s, &t);
        Dijkstra(mark_id[s]);
        printf("%d\n", dis[mark_id[t]]);
    }
    return 0;
}
