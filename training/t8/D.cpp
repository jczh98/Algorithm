#include <bits/stdc++.h>
#define MN 10000000
#define inf 2139062143
using namespace std;
int m,n,grid[1000][1000],dis[MN],vis[MN];
char mp[1000][1000];
struct Edge
{
    int to,nxt,w;
}edge[MN];
int cnt=1,head[MN];
void AddEdge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void Dijkstra()
{
    priority_queue<pair<int,int> > pq;
    memset(dis,127,sizeof(dis));
    dis[1*n+1]=0;vis[1*n+1]=1;
    pq.push(make_pair(1*n+1,dis[1*n+1]));
    while(!pq.empty())
    {
        int now=pq.top().first;pq.pop();vis[now]=0;
        for(int i=head[now];i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(dis[v]>dis[now]+edge[i].w)
            {
                dis[v]=dis[now]+edge[i].w;
                if(!vis[v])vis[v]=1,pq.push(make_pair(v,dis[v]));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)scanf("%s",mp[i]+1);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)grid[i][j]=mp[i][j]-'0';
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int step=grid[i][j];
            if(i+step<=m)AddEdge(i*n+j,(i+step)*n+j,1);
            if(j+step<=n)AddEdge(i*n+j,i*n+j+step,1);
            if(i-step>=1)AddEdge(i*n+j,(i-step)*n+j,1);
            if(j-step>=1)AddEdge(i*n+j,i*n+j-step,1);
        }
    }
    Dijkstra();
    if(dis[m*n+n]==inf)
    {
        printf("IMPOSSIBLE\n");
    }else printf("%d\n",dis[m*n+n]);
    return 0;
}
