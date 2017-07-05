#include <bits/stdc++.h>
#define N 1010
using namespace std;
int t,n,a[N],f[N],len,vis[N],ans[N];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(f,0,sizeof(f));memset(vis,0,sizeof(vis));memset(ans,0,sizeof(ans));
        f[1]=a[1];len=1;int j=1;vis[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(f[len]<a[i])j=++len;
            else j=(lower_bound(f+1,f+1+len,a[i])-f);
            f[j]=a[i];
            vis[i]=j;
        }
        printf("%d ",len);
        int t=n;
        for(int i=len;i>=1;i--)
        {
            for(int j=t;j>=1;j--)
            {
                if(vis[j]==i)
                {
                    ans[i]=a[j],t=j;
                    break;
                }
            }
        }
        for(int i=1;i<=len;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
