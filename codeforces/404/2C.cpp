#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
LL n,m,ans;
void Bisction()
{
    LL l=1LL,r=(1LL<<31);
    while(l<r)
    {
        LL mid=(l>>1)+(r>>1);
        if(((mid*(mid+1)>>1))<(n-m))
        {
            l=mid+1;
        }else
        {
            r=mid;
        }
    }
    ans=l+m;
}
int main()
{
    cin>>n>>m;
    if(n<=m)
    {
        cout<<n;return 0;
    }
    Bisction();
    cout<<ans<<endl;
    return 0;
}
