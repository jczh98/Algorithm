#include <cstdio>
int n,k,a[100000],kth=0,ans=0;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==k)kth=a[i];
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]>=kth&&a[i]>0)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
