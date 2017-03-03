#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 100+10
using namespace std;

int mat[MN][MN],n,m,cnt,a,b,vis[MN],topo[MN];

bool Dfs(int u)
{
    vis[u]=-21;
    for(int v=1;v<=n;v++)
    {
        if(mat[u][v])
            if(vis[v]<0)return false;
            else if(!vis[v]&&!Dfs(v))return false;
    }
    vis[u]=1;topo[cnt--]=u;
    return true;
}


int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        memset(mat,0,sizeof(mat));
        memset(vis,0,sizeof(vis));
        cnt=n;
        for(int i=1;i<=m;i++)
        {
            cin>>a>>b;
            mat[a][b]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])Dfs(i);
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",topo[i]);
        }printf("\n");
    }
}
