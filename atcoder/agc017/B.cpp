#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,b,c,d;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
    for(int i=0;i<n;i++)
    {
        LL l=a+i*c-(n-1-i)*d,r=a+i*d-(n-1-i)*c;
        if(l<=b&&b<=r)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
