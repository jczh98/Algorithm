#include <bits/stdc++.h>
#define MN 100
using namespace std;
typedef long long LL;
LL ans=1,n,a[MN],cnt[MN];
int main()
{
    scanf("%lld",&n);
    for(int i=0;i<=60;i++)cnt[i]=-1;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<n;i++)
    {
        for(int j=59;j>=0;j--)
        {
            if(((a[i]>>j)&1)!=((a[i+1]>>j)&1))
            {
                if((a[i]>>j)&1)
                {
                    if(cnt[j]==0)
                    {
                        printf("0\n");
                        return 0;
                    }
                    cnt[j]=1;
                }else
                {
                    if(cnt[j]==1)
                    {
                        printf("0\n");
                        return 0;
                    }
                    cnt[j]=0;
                }
                break;
            }
        }
    }
    for(int i=0;i<=59;i++)if(cnt[i]==-1)ans<<=1;
    printf("%lld\n",ans);
    return 0;
}
