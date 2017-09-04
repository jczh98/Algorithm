#include <bits/stdc++.h>
#define MAXN 300300
using namespace std;
vector<int> G[MAXN];
int dep[MAXN],par[MAXN][25],lg=20;
void Dfs(int u,int fa)
{
    for(int i=1;i<lg;i++)
    {
        par[u][i]=par[par[u][i-1]][i-1];
    }
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa||dep[v])continue;
        dep[v]=dep[u]+1;
        par[v][0]=u;
        Dfs(v,u);
    }
}
int Lca(int v,int u)
{
    if(dep[v]>dep[u])swap(v,u);
    for(int i=0;i<lg;i++)
        if(dep[u]-dep[v]>>i&1)u=par[u][i];
    for(int i=lg-1;i>=0;i--)
        if(par[v][i]!=par[u][i])
            v=par[v][i],u=par[u][i];
    return v==u?v:par[v][0];
}
int Cal(int f,int s,int t)
{
    int lca1=Lca(f,s),lca2=Lca(f,t),lca3=Lca(s,t);
    bool l1=lca1==f,l2=lca2==f;
    if(l1!=l2)return 1;
    if(l1) return max(0,dep[lca3]-dep[f])+1;
    else if(lca1!=lca2) return max(0,dep[f]-max(dep[lca1],dep[lca2]))+1;
    else return max(0,dep[f]+dep[lca3]-2*dep[lca1])+1;
}
int n,q;
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        G[i].push_back(x);
        G[x].push_back(i);
    }
    Dfs(1,0);
    for(int i=1;i<=q;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",max(Cal(a,b,c),max(Cal(b,c,a),Cal(c,a,b))));
    }
    return 0;
}
