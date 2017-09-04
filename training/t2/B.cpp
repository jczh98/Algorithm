#include <bits/stdc++.h>
#define MN 100100
using namespace std;
int n,kase=1,ans,a[MN],cnt[MN];
int Gcd(int a,int b)
{
    if(a<b)swap(a,b);
    return b==0?a:Gcd(b,a%b);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int t=a[1];
        for(int i=2;i<=n;i++)t=Gcd(t,a[i]);
        if(t!=1)
        {
            printf("Case %d: -1\n",kase++);
        }else
        {
            printf("Case %d: %d\n",kase++,2*(n-1));
            for(int i=2;i<=n;i++)
            {
                printf("1 %d\n",i);
            }
            for(int i=2;i<=n;i++)
            {
                printf("1 %d\n",i);
            }
        }
        printf("\n");
    }
    return 0;
}
