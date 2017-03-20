#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n,m,k,fa[1000000],ans=0,v[200][200],cnt[1000],cnt0=0;
int Find(int x)
{
    return x==fa[x]?fa[x]:fa[x]=Find(fa[x]);
}
int main()
{
    memset(v,0,sizeof(v));
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<=100000;i++)fa[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&k);
        if(k==0)cnt0++;
        for(int j=1;j<=k;j++)
        {
            int x;scanf("%d",&x);
            v[x][cnt[x]++]=i;
        }
    }
    if(cnt0==n)
    {
        printf("%d\n",n);
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<cnt[i]-1;j++)
        {
            int x=Find(v[i][j]),y=Find(v[i][j+1]);
            if(x!=y)
            {
                fa[x]=y;
            }
        }
    }
    for(int i=1;i<=n;i++)if(fa[i]==i)ans++;
    printf("%d\n",ans-1);
    return 0;
}
