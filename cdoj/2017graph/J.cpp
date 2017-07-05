#include <bits/stdc++.h>
#define MN 550
#define inf 1000000
using namespace std;
int n,p,q,s,t,sum[MN],vis[MN],in[MN];
struct Edge
{
    int to,nxt,w;
}e[MN*MN];
int cnt=1,head[MN];
void Add(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=w;
    head[u]=cnt++;
}
int Spfa(int s)
{
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    for(int i=0;i<=n;i++)sum[i]=inf;
    queue<int> que;
    sum[s]=0;vis[s]=1;
    que.push(s);
    while(!que.empty())
    {
        int now=que.front();que.pop();vis[now]=0;
        for(int i=head[now];i;i=e[i].nxt)
        {
            int v=e[i].to;
            if(sum[v]>sum[now]+e[i].w)
            {
                sum[v]=sum[now]+e[i].w;
                if(!vis[v])
                {
                    in[v]++;
                    if(in[v]>n)return false;
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
    }
    return true;
}
int main()
{
    scanf("%d%d%d%d%d",&n,&p,&q,&s,&t);
    memset(head,0,sizeof(head));
    for(int i=1;i<=n;i++)Add(n+1,i,0);
    for(int i=0;i<=n;i++)
    {
        if(i+p<=n)Add(i+p,i,-s);
        if(i+q<=n)Add(i,i+q,t);
    }
    int f=Spfa(n+1);
    if(f)
    {
        printf("Yes\n");
        for(int i=1;i<=n;i++)
        {
            printf("%d ",sum[i]-sum[i-1]);
        }
    }else
    {
        printf("No\n");
    }
}

