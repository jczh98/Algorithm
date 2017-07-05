#include <bits/stdc++.h>
#define MN 100100
using namespace std;
typedef long long LL;
int n;
LL fa[MN],ord[MN],e[MN],p[MN],ans[MN],cur;
LL Find(LL x)
{
    return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);
}
void Union(LL x,LL y)
{
    LL a=Find(x),b=Find(y);
    if(a!=b)fa[a]=b;
}
int main()
{
    memset(p,0,sizeof(p));
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&e[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&ord[i]);
    for(int i=1;i<=n;i++)fa[i]=(LL)i;
    cur=0;
    for(int i=n;i>=1;i--)
    {
        ans[i]=cur;
        LL now=ord[i];
        p[now]=e[now];
        if(p[now-1]>0)
        {

            LL t=p[Find(now)]+p[Find(now-1)];
            Union(now-1,now);
            p[Find(now)]=t;
        }
        if(p[now+1]>0)
        {
            LL t=p[Find(now)]+p[Find(now+1)];
            Union(now+1,now);
            p[Find(now)]=t;
        }
        LL t=Find(now);
        if(p[t]>cur)cur=p[t];
    }
    for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}
