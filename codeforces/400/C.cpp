#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
int n,k;
LL a[100100],sum[100100];
LL ans=0;
map<LL,int> mp;
int main()
{
	memset(sum,0,sizeof(sum));
    mp.clear();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    sum[0]=0;
    if(k==1||k==-1)
    {
        for(int i=1;i<=n;i++)
        {
            if(k==-1)mp[sum[i-1]-1]++;
            mp[sum[i-1]+1]++;
            sum[i]=sum[i-1]+a[i];
            ans+=mp[sum[i]];
        }
    }else for(int i=1;i<=n;i++)
    {
        for(LL j=1;abs(j)<=1e16+10;j*=(LL)k)
        {
            mp[sum[i-1]+j]++;
        }
        sum[i]=sum[i-1]+a[i];
        ans=ans+mp[sum[i]];
    }
    cout<<ans<<endl;
    return 0;
}
