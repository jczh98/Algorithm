#include <bits/stdc++.h>
using namespace std;
int t,n,a[1000],b[1000],ans,tot;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),tot+=a[i];
        for(int i=1;i<=n;i++)
        {
            b[i]=a[i];
            for(int j=1;j<i;j++)
            {
                if(a[j]<=a[i])
                {
                    b[i]=max(b[i],b[j]+a[i]);
                }
            }
            cout<<b[i]<<endl;
            ans=max(ans,b[i]);
        }
        printf("%d\n",tot-ans);
    }
    return 0;
}
