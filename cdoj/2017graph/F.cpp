#include <bits/stdc++.h>
#define N 100100
#define M 1000100
#define inf 1e12
using namespace std;
typedef pair<int,int> pii;
int n,m,k,d,x,y,z,ki[N],cls[N];
long long f[N];
struct Edge
{
    int to,nxt,w;
}e[2*M];
int cnt=1,head[N];
void Add(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=w;
    head[u]=cnt++;
}
void Dijkstra()
{
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    for(int v=0;v<n;v++)if(!f[v])
    {
        for(int i=head[v];i;i=e[i].nxt)
        {
            int u=e[i].to;
            pq.push(make_pair(f[v]+e[i].w,u));
        }
    }
    while(!pq.empty())
    {
        pii now=pq.top();int u=now.second;
        if(f[u]!=inf)
        {
            pq.pop();continue;
        }
        if(cls[u]<d)cls[u]++;
        else if(cls[u]==d)
        {
            f[u]=now.first;
            for(int i=head[u];i;i=e[i].nxt)
            {
                int uu=e[i].to;
                pq.push(make_pair(f[u]+e[i].w,uu));
            }
        }
        pq.pop();
    }
}
int main()
{
    memset(head,0,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&k,&d);
    memset(cls,0,sizeof(cls));
    for(int i=0;i<n;i++)f[i]=inf;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
        Add(y,x,z);
    }
    for(int i=1;i<=k;i++)scanf("%d",&ki[i]),f[ki[i]]=0;
    Dijkstra();
    if(f[0]==inf)printf("-1\n");
    else printf("%lld\n",f[0]);
    return 0;
}

