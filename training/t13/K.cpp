#include <bits/stdc++.h>
#define MAXN 500500
#define MAXM 500500
#define inf 0x7f7f7f7f
using namespace std;
typedef pair<int,int> pii;
int n,m,start,terminal,r,vis[MAXN],dis[MAXN],pre_dis[MAXN],mid=0,shortest_path;
struct Edge
{
    int to,nxt,w;
}edge[MAXM];
int cnt=1,head[MAXN];
void AddEdge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void Dijkstra(int s)
{
    memset(vis,0,sizeof(vis));
    memset(dis,127,sizeof(dis));
    priority_queue<pii >pq;
    vis[s]=1;dis[s]=0;
    pq.push(make_pair(s,dis[s]));
    if(pre_dis[s]<=mid)return;
    while(!pq.empty())
    {
        int now=pq.top().first;pq.pop();vis[now]=0;
        for(int i=head[now];i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(pre_dis[v]<=mid)continue;
            if(dis[v]>dis[now]+edge[i].w)
            {
                dis[v]=dis[now]+edge[i].w;
                if(!vis[v])
                {
                    vis[v]=1;
                    pq.push(make_pair(v,dis[v]));
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        AddEdge(a,b,1);
        AddEdge(b,a,1);
    }
    scanf("%d%d%d",&start,&terminal,&r);
    memset(pre_dis,127,sizeof(pre_dis));
    Dijkstra(r);
    for(int i=1;i<=n;i++)pre_dis[i]=dis[i];
    Dijkstra(start);
    shortest_path=dis[terminal];
    if(shortest_path==inf)
    {
        printf("0\n");
        return 0;
    }
    int l=0,r=n;
    while(l<r)
    {
        mid=(l+r)/2;
        Dijkstra(start);
        if(dis[terminal]==shortest_path) l=mid+1;
        else r=mid;
    }
    printf("%d\n",l);
    return 0;
}
