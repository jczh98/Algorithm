#include <cstdio>
#include <climits>
int n,l,r,a[100100],p[100100],cnt[100100],b[100100],ans[100100];
int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]),cnt[p[i]]=a[i];
    int k=INT_MIN,flag=1;
    for(int i=1;i<=n;i++)
    {
        int t=l;
        if(t-cnt[i]>k)b[i]=t,k=t-cnt[i];
        else
        {
            if(k+1+cnt[i]<=r)b[i]=k+1+cnt[i],k=k+1;
            else
            {
                flag=0;break;
            }
        }
    }
    if(flag==0)
    {
        printf("-1\n");return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ans[i]=b[p[i]];
    }
    for(int i=1;i<n;i++)printf("%d ",ans[i]);printf("%d\n",ans[n]);
    return 0;
}
