#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;
struct Edge{
    int to, nxt;
}edge[1000005];
int cnt = 0, head[1000005];
inline void Init() {
    cnt = 0;
    memset(head, -1, sizeof(head));
}
inline void Add(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
int t, n, m, s, u, v, dis[1000005];
set<int> s1, s2;
set<int>::iterator it;
inline void BFS() {
    queue<int> que;
    que.push(s);
    dis[s] = 0;
    while(!que.empty()) {
        int now = que.front(); que.pop();
        for(int i = head[now]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(!s1.count(v)) continue;
            s1.erase(v); s2.insert(v);
        }
        for(it = s1.begin(); it != s1.end(); it++) {
            dis[*it] = dis[now] + 1;
            que.push(*it);
        }
        s1.swap(s2);
        s2.clear();
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        Init();
        memset(dis, -1, sizeof(dis));
        s1.clear();
        s2.clear();
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            Add(u, v); Add(v, u);
        }
        scanf("%d", &s);
        for(int i = 1; i <= n; i++) {
            if(i == s) continue;
            s1.insert(i);
        }
        BFS();
        for(int i = 1; i <= n; i++) {
            if(i == s) continue;
            printf("%d%c", dis[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}

