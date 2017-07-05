#include <bits/stdc++.h>
#define MN 1010
using namespace std;
int n,cnt=1,fa[MN],ans=0;
struct Edge
{
    int u,v,w;
    bool operator < (const Edge &rhs)const
    {
        return w<rhs.w;
    }
}e[MN*MN];
int Find(int x){return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);}
void Kruskal()
{
    for(int i=0;i<MN;i++)fa[i]=i;
    sort(e+1,e+cnt);
    for(int i=1;i<cnt;i++)
    {
        int x=Find(e[i].u),y=Find(e[i].v);
        if(x!=y)
        {
            fa[x]=y;
            ans+=e[i].w;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            scanf("%d",&e[cnt].w);
            e[cnt].u=i-1;e[cnt].v=j;cnt++;
        }
    }
    Kruskal();
    printf("%d\n",ans);
    return 0;
}
