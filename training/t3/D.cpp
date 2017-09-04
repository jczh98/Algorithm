#include <bits/stdc++.h>
#define MN 100100
using namespace std;
struct Edge
{
    int u,v,w;
    bool operator < (const Edge &rhs) const
    {
        return w<rhs.w;
    }
}edge[MN];
int fa[MN];
int Find(int x)
{
    return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);
}
void ClearFa()
{
    for(int i=0;i<MN;i++)fa[i]=i;
}
int t,n,m,cnt_min,cnt_max,kase=1,fib[MN],tot=2,cnt;
bool Kruskal()
{
    ClearFa();
    sort(edge+1,edge+1+m);
    cnt=0;
    cnt_min=0;
    for(int i=1;i<=m;i++)
    {
        int x=Find(edge[i].u);
        int y=Find(edge[i].v);
        if(x!=y)
        {
            fa[x]=y;
            cnt++;
            cnt_min+=edge[i].w;
        }
    }
    if(cnt!=n-1) return false;
    ClearFa();
    cnt_max=0;
    for(int i=m;i>=1;i--)
    {
        int x=Find(edge[i].u);
        int y=Find(edge[i].v);
        if(x!=y)
        {
            fa[x]=y;
            cnt_max+=edge[i].w;
        }
    }
    return true;
}
void Pre()
{
    fib[1]=fib[0]=1;
    while(fib[tot-1]+fib[tot-2]<=MN)
    {
        fib[tot]=fib[tot-1]+fib[tot-2];tot++;
    }
}
int main()
{
    Pre();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        if(!Kruskal())
        {
            printf("Case #%d: No\n",kase++);
            continue;
        }
        int flag=0;
        for(int i=1;i<tot;i++)
        {
            if(fib[i]>=cnt_min&&fib[i]<=cnt_max)
            {
                flag=1;break;
            }
        }
        if(flag) printf("Case #%d: Yes\n",kase++);
        else printf("Case #%d: No\n",kase++);
    }
    return 0;
}
