#include <bits/stdc++.h>
#define MN 2048576
#define inf 1e15+7
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,m;
struct Edge
{
    int to,next;
    LL c;
}e[100100];
int cnt=1,head[MN],t1,t2,temp,vis[MN];
char s1[100],s2[100];
LL dis[MN],w;
int Add(int u,int v,LL c)
{
    e[cnt].to=v;
    e[cnt].c=c;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
int Spfa()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<MN;i++)dis[i]=inf;
    queue<int> que;
    que.push(1);vis[1]=1;dis[1]=0;
    while(!que.empty())
    {
        int u=que.front();que.pop();
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(!vis[v])
            {
                if(dis[v]>dis[u]+e[i].c)
                {
                    dis[v]=dis[u]+e[i].c;
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main()
{
    memset(head,0,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%s%s%lld",&s1,&s2,&w);
        temp=1;t1=t2=0;
        for(int j=n-1;j>=0;j--)
        {
            t1+=temp*(s1[j]-'0');
            t2+=temp*(s2[j]-'0');
            temp*=2;
        }
        Add(t1+1,t2+1,w);
    }
    /*for(int i=1;i<cnt;i++)
    {
        cout<<e[i].to<<" "<<e[i].c<<endl;
    }*/
    Spfa();
    int mx=0;for(int i=0;i<=n-1;i++)mx^=(1<<i);
    //cout<<mx<<endl;
    //for(int i=1;i<=mx+1;i++)printf("%d ",dis[i]);
    if(dis[mx+1]==inf)
    {
        printf("-1\n");
    }else
    {
        printf("%lld\n",dis[mx+1]);
    }
    return 0;
}
