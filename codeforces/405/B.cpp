#include <cstdio>
#include <cstring>
int n,m,fa[10000100],rk[10000100],edge[10000100],cnt[10000100];
int Find(int x)
{
    return fa[x]==x?fa[x]:fa[x]=Find(fa[x]);
}
void Union(int u,int v)
{
    int x=Find(u), y=Find(v);
    if(rk[x]>=rk[y])
    {
        fa[y]=x;
        rk[x]+=rk[y];
    }else
    {
        fa[x]=y;
        rk[y]+=rk[x];
    }
}
int main()
{
    memset(edge,0,sizeof(edge));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=10000000;i++)fa[i]=i,rk[i]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u]++;edge[v]++;
        Union(u,v);
    }
    for(int i=1;i<=n;i++)
    {
        cnt[fa[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(edge[i]!=cnt[fa[i]]-1)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
