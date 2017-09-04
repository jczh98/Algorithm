#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int n;
struct Edge
{
    int to,nxt,inv;
}edge[5000000];
int cnt=1,head[5000000],f[5000000],ans=inf;
vector<int> city;
void AddEdge(int u,int v,int inv)
{
    edge[cnt].to=v;
    edge[cnt].nxt=head[u];
    edge[cnt].inv=inv;
    head[u]=cnt++;
}
int Dfs(int x,int fa)
{
    f[x]=0;
    for(int i=head[x];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(v==fa)continue;
        Dfs(v,x);
        f[x]+=f[v]+edge[i].inv;
    }
}
int Dfs2(int x,int fa)
{
    for(int i=head[x];i;i=edge[i].nxt)
    {
        int v=edge[i].to;;
        if(v==fa)continue;
        f[v]=f[x];
        if(edge[i].inv)f[v]-=1;
        else f[v]+=1;
        Dfs2(v,x);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        AddEdge(x,y,0);
        AddEdge(y,x,1);
    }
    Dfs(1,-1);
    Dfs2(1,-1);
    for(int i=1;i<=n;i++)ans=min(ans,f[i]);
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
    {
        if(f[i]==ans)city.push_back(i);
    }
    for(int i=0;i<city.size()-1;i++)
    {
        printf("%d ",city[i]);
    }
    printf("%d\n",city[city.size()-1]);
    return 0;
}
