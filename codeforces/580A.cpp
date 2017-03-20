#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL n,a[1000000],cnt=1,ans=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i+1])cnt++,ans=max(ans,cnt);
        else cnt=1;
    }
    cout<<ans<<endl;
    return 0;
}
