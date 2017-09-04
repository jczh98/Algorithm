#include <bits/stdc++.h>
using namespace std;
int n,k,t[100100],ans=1,last=1;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&t[i]);
    for(int i=1;i<=n;i++)
    {
        while(t[i]-t[last]>=1000)last++;
        ans=max(ans,i-last+1);
    }
    printf("%d\n",ans%k==0?ans/k:ans/k+1);
    return 0;
}
