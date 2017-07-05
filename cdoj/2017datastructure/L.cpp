#include <bits/stdc++.h>
#define MN 100000
using namespace std;
int fa[MN],rk[MN],n,m;
int Find(int x)
{
    if(x==fa[x])
    {
        return fa[x];
    }else
    {
        int t=fa[x];
        fa[x]=Find(fa[x]);
        rk[x]=(rk[x]+rk[t])%3;
        return fa[x];
    }
}
int Judge(int d,int x,int y)
{
    if(x>n||y>n)return false;
    if(d==2&&x==y)return false;
    if(Find(x)==Find(y))
    {
        if(d==2)return (rk[x]-rk[y]+3)%3==1;
        else return rk[x]==rk[y];
    }
    return true;
}
int k,a,b,ans[MN+10],cnt=0,anss=0;
int main()
{
    for(int i=0;i<MN;i++)fa[i]=i,rk[i]=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(Judge(k,a,b))
        {
            int x=Find(a),y=Find(b);
            if(x!=y)
            {
                fa[x]=y;rk[x]=(rk[b]-rk[a]+k-1+3)%3;
            }
        }else
        {
            ans[cnt++]=i;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}
