#include <cstdio>
#include <cmath>
#include <cstring>
int n,a[10000],b[10000],tot[10],cnta[10],cntb[10],dif[10],ans=0;
int main()
{
    memset(tot,0,sizeof(tot));
    memset(cnta,0,sizeof(cnta));
    memset(cntb,0,sizeof(cntb));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),tot[a[i]]++,cnta[a[i]]++;
    for(int i=1;i<=n;i++)scanf("%d",&b[i]),tot[b[i]]++,cntb[b[i]]++;
    for(int i=1;i<=5;i++)if(tot[i]%2)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1;i<=5;i++)dif[i]=(cnta[i]-cntb[i])/2;
    for(int i=1;i<=5;i++)if(dif[i]>0)ans+=dif[i];
    printf("%d\n",ans);
    return 0;
}
