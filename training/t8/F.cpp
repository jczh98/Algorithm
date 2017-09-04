#include <bits/stdc++.h>
using namespace std;
int n,a[100100],ans=INT_MAX;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n/2;i++)
    {
        ans=min(ans,a[i]+a[n-i+1]);
    }
    printf("%d\n",ans);
    return 0;
}
