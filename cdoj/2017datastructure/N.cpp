#include <bits/stdc++.h>
#define MN 1000100
using namespace std;
int fa[MN],rk[MN];
int Find(int x)
{
    if(x==fa[x])
    {
        return fa[x];
    }else
    {
        int t=fa[x];
        fa[x]=Find(fa[x]);
        rk[x]=(rk[t]+rk[x])%2;
        return fa[x];
    }
}
int n,m,t,a,b,f=0;
int main()
{
    for(int i=1;i<MN;i++)fa[i]=i,rk[i]=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&t,&a,&b);
        int x=Find(a),y=Find(b);
        if(x!=y)
        {
            fa[x]=y;
            rk[x]=(rk[b]+rk[a]+1-t)%2;
        }else
        {
            if((rk[a]+rk[b])%2==t)f=1;
        }
    }
    if(!f)printf("YES\n");
    else printf("NO\n");
    return 0;
}
