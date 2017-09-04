#include <bits/stdc++.h>
#define M 200200
#define N 100100
using namespace std;
struct Edge
{
    int to,nxt,w;
}edge[M];
int cnt=1,head[N],v,e,s,t,dis[N],vis[N],f[N];
struct cmp
{
    bool operator ()(int a,int b){
        return dis[a]>dis[b];
    }
};
void AddEdge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void Spfa(int x)
{
    memset(dis,127,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<int,vector<int>,cmp > pq;
    dis[x]=0;vis[x]=1;f[x]=1;
    pq.push(x);
    while(!pq.empty())
    {
        int now=pq.top();pq.pop();
        //vis[now]=0;
        for(int i=head[now];i;i=edge[i].nxt)
        {
            int to=edge[i].to;
            //cout<<"#"<<now<<" "<<to<<endl;
            if(dis[to]>dis[now]+edge[i].w)
            {
                dis[to]=dis[now]+edge[i].w;
                f[to]=f[now];
                if(!vis[to])
                {
                    vis[to]=1;
                    pq.push(to);
                }
            }else if(dis[to]==dis[now]+edge[i].w)
            {
                f[to]+=f[now];
            }
        }
    }
}
int main()
{
    scanf("%d%d",&v,&e);
    for(int i=1;i<=e;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        AddEdge(x+1,y+1,z);
    }
    scanf("%d%d",&s,&t);
    Spfa(s+1);
    //for(int i=1;i<=v;i++)cout<<f[i]<<endl;
    printf("%d\n",f[t+1]);
    return 0;
}
