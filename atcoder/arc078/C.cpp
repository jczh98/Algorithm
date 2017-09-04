#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,a[200200];
LL sum[200200]={0},ans=(1LL<<60);
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    for(int i=1;i<n;i++)
    {
        LL snuke=sum[i]-sum[0],raccon=sum[n]-sum[i];
        ans=min(ans,abs(snuke-raccon));
    }
    cout<<ans<<endl;
    return 0;
}
