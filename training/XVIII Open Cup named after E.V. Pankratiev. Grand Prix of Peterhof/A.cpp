#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i, x, y) for (int i = x; i < y + 1; i++)
#define fs(i, x, y) for (int i = x; i > y - 1; i--)
#define all(x) x.begin(), x.end()
#define Ins(x) inserter(x, x.begin())
#define pi 3.14159265358979323846
#define MAXN 1000005
using namespace std;
typedef long long ll;
ll n,k;
int ans[7]={0,6,8,9,11,12,12};
int main()
{
    scanf("%lld",&n);
    k=0;
    if(n<=5)
        printf("%d\n",ans[n]);
    else if(n<=7)
        printf("12\n");
    else
    {
        n-=7;
        ll mid,l=1,r=1e5;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(3*mid*(3+mid)>n)
            r=mid-1;
            else
            {
                k=mid;
                l=mid+1;
            }
        }
       if(3*k*(3+k)!=n)
        k++;
        n-=3*(k-1)*(2+k);
        if(n<=k)
            printf("%lld\n",(k-1)*6+13);
        else if(n<=5*k+4)
            printf("%lld\n",(k-1)*6+13+1+(n-k-1)/(k+1));
        else
        printf("%lld\n",(k-1)*6+13+5);
    }
    return 0;
}
