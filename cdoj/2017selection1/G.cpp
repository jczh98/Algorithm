#include <bits/stdc++.h>
#define MN 1001000
using namespace std;
typedef long long LL;
char str[MN];
int main()
{
    scanf("%s",str);
    int len=strlen(str);
    if(len<10)
    {
        LL ans=1;
        for(LL i=1;;i++)
        {
            ans*=i;
            if(ans==atoi(str))
            {
                printf("%lld\n",i);
                break;
            }
        }
    }else
    {
        double ans=1;
        for(LL i=1;;i++)
        {
            ans+=log10(i);
            if(floor(ans)==len)
            {
                printf("%lld",i);
                break;
            }
        }
    }
    return 0;
}
