#include <bits/stdc++.h>
#define M 2002000
#define N 10020
using namespace std;
typedef pair<int,int> pii;
struct Edge
{
    int to,nxt,d,c;
}edge[M];
int n,m,head[M],cnt,dis[N],cost[N],vis[N],ans=0;
void AddEdge(int u,int v,int d,int c)
{
    edge[cnt].to=v;
    edge[cnt].d=d;
    edge[cnt].c=c;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void Dijkstra()
{
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    memset(cost,127,sizeof(cost));
    queue<int> que;
    vis[1]=1;dis[1]=0;cost[1]=0;
    pq.push(make_pair(1,dis[1]));
    while(!pq.empty())
    {
        int now=pq.top().first;pq.pop();
        vis[now]=0;
        for(int i=head[now];i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(dis[v]>dis[now]+edge[i].d||(dis[v]==dis[now]+edge[i].d&&cost[v]>edge[i].c))
            {
                dis[v]=dis[now]+edge[i].d;
                cost[v]=edge[i].c;
                if(!vis[v])pq.push(make_pair(v,dis[v])),vis[v]=1;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        memset(edge,0,sizeof(edge));
        memset(head,0,sizeof(head));
        cnt=1;
        for(int i=1;i<=m;i++)
        {
            int u,v,d,c;;
            scanf("%d%d%d%d",&u,&v,&d,&c);
            AddEdge(u,v,d,c);
            AddEdge(v,u,d,c);
        }
        Dijkstra();
        ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=cost[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
