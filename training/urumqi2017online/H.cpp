#include <bits/stdc++.h>
#define MAXN 10005
#define MAXM 100005
using namespace std;
typedef long long LL;
struct Edge{
    int to, nxt, c;
}edge[MAXM];
int cnt = 0, head[MAXN];
void Init(){
    cnt = 0;
    memset(head, -1, sizeof(head));
}
void Add(int u, int v, int c) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    edge[cnt].c = c;
    head[u] = cnt++;
}
int vis[MAXN], indeg[MAXN];
LL ans[MAXN];
LL answer = 0;
LL dfs(int cur)
{
    if(ans[cur] != -1) return ans[cur];
    LL tmp = 0;
    for (int i = head[cur]; ~i; i = edge[i].nxt)
    {
        int to = edge[i].to;
        LL lenth = edge[i].c;
        tmp = max(tmp, dfs(to) + lenth);
    }
    return ans[cur] = tmp;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        answer = 0;
        Init();
        memset(indeg, 0, sizeof(indeg));
        memset(ans, -1, sizeof(ans));
        int n, m;
        int from, to, lenth;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &from, &to, &lenth);
            indeg[to]++;
            Add(from, to, lenth);
        }
        for (int i = 1; i <= n; i++)
        {
            if (indeg[i] == 0)
            {
                answer = max(answer, dfs(i));
            }
        }
        cout << answer << endl;
    }
    return 0;
}
