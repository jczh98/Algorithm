#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,k,p,a[2000],b[3000];
LL ans=(1LL<<60);
int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=k;i++)scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+k);
    for(int i=1;i+n-1<=k;i++)
    {
        LL t=0;
        for(int j=1;j<=n;j++)
        {
            t=max((LL)abs(a[j]-b[j+i-1])+(LL)abs(b[j+i-1]-p),t);
        }
        ans=min(t,ans);
    }
    cout<<ans<<endl;
    return 0;
}
