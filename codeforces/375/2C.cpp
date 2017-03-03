#include <cstdio>
#include <cstring>
#define MN 10000

int n,m,a[MN],cnt[MN],ans1,ans2,vis[MN];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    ans1=n/m;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(a[i]>m)continue;
        if(cnt[a[i]]>=ans1)continue;
        cnt[a[i]]++;
        vis[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int t1=1e9,t2=1e9;
        for(int j=1;j<=m;j++)
        {
            if(cnt[j]<t2)
            {
                t2=cnt[j];t1=j;
            }
        }
        if(t2==ans1)continue;
        ans2++;
        cnt[t1]++;
        a[i]=t1;
    }
    printf("%d %d\n",ans1,ans2);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
