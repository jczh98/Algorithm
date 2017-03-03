#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
typedef long long LL;
int n;
LL ans;
int main()
{
    int kase=1;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        if(n==0)return 0;
        if(n==1)
        {
            printf("Case %d: 2\n",kase++);
            continue;
        }
        int cnt=0,m=sqrt(n+1);
        for(int i=2;i<=m;i++)
        {
            if(n%i==0)
            {
                cnt++;LL t=1;
                while(n%i==0)
                {
                    t*=i;n/=i;
                }
                ans+=t;
            }
        }
        if(cnt==0)ans+=((LL)n+1);
        if(cnt==1||(cnt!=0&&n!=1))ans+=n;
        printf("Case %d: %lld\n",kase++,ans);
    }
    return 0;
}
