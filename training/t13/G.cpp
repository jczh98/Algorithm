#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,person[200],tot;
LL f[300030]={0};
int main()
{
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        memset(f,0,sizeof(f));
        tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&person[i]);tot+=person[i];
        }
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=tot/2;j>=person[i];j--)
            {
                f[j]|=f[j-person[i]]<<1;
            }
        }
        int ans;
        for(ans=tot/2+1;ans>=0;ans--)
        {
            if(n&1)
            {
                int t1=(n+1)/2,t2=n/2;
                if((f[ans]>>t1)&1)break;
                if((f[ans]>>t2)&1)break;
            }else
            {
                int t1=n/2;
                if((f[ans]>>t1)&1)break;
            }
		}
		printf("Case %d: %d %d\n",k,min(ans,tot-ans),max(ans,tot-ans));
    }
    return 0;
}
