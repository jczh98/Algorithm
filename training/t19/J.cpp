#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL n,m,c[10000],f[10000][10000],ans;
int main()
{
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m;
        memset(f,0,sizeof(f));
        ans=0;
        for(int i=1;i<=n;i++)cin>>c[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(m>=c[i])
                {
                    f[i][j]=max(f[i-1][j+1]+c[i],f[i-1][j-1]-c[i]);
                    m-=c[i];
                }else
                {
                    f[i][j]=f[i-1][j+1]+c[i];
                }
            }
        }
        for(int i=0;i<=n;i++)ans=max(ans,f[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}
