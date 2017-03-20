#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
using namespace std;
typedef long long LL;
LL n,m,l1,l2,r1,r2,minr1=INT_MAX,maxl2=INT_MIN,minr2=INT_MAX,maxl1=INT_MIN,ans1,ans2;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l1>>r1;
        minr1=min(r1,minr1);
        maxl1=max(l1,maxl1);
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>l2>>r2;
        maxl2=max(l2,maxl2);
        minr2=min(r2,minr2);
    }
    if(minr1>maxl2)ans1=0;
    else ans1=maxl2-minr1;
    if(minr2>maxl1)ans2=0;
    else ans2=maxl1-minr2;
    cout<<max(ans1,ans2)<<endl;
    return 0;
}
