#include <bits/stdc++.h>
using namespace std;
int t,n,p[200100],q[200100],fa[200100],e[200100],c[200100],flag;
int Find(int x)
{
    return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        memset(e,0,sizeof(e));
        memset(c,0,sizeof(c));
        for(int i=1;i<200100;i++)fa[i]=i;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i],&q[i]);
            int x=Find(p[i]),y=Find(q[i]);
            if(x!=y)fa[x]=y;
        }
        for(int i=1;i<=n;i++)e[Find(p[i])]++;
        for(int i=1;i<=2*n;i++)c[Find(i)]++;
        int i;
        for(i=1;i<=2*n;i++)
        {
            int j=Find(i);
            if(e[j]>c[j]) flag=1;break;
        }
        if(flag)printf("impossible\n");
        else printf("possible\n");
    }
    return 0;
}
