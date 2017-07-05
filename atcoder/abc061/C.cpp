#include <bits/stdc++.h>
#define MN 100100
using namespace std;
typedef long long LL;
int n;
struct Com
{
    int a,b;
}num[MN];
int cmp(Com x,Com y)
{
    return x.a<y.a;
}
LL k,sum[MN];
int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&num[i].a,&num[i].b);
    }
    sort(num+1,num+1+n,cmp);
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+num[i].b;
    }
    int pos=lower_bound(sum+1,sum+1+n,k)-sum;
    printf("%d\n",num[pos].a);
    return 0;
}
