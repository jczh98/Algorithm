#include <bits/stdc++.h>
#define N 550
using namespace std;
typedef long long LL;
int n,m,b,mod,a[N],c;
LL f[N][N],ans=0;
int main()
{
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=b;k++)
            {
                if(k-a[i]>=0)f[j][k]+=f[j-1][k-a[i]],f[j][k]%=mod;
            }
        }
    }
    for(int i=0;i<=b;i++)ans+=f[m][i],ans%=mod;
    printf("%lld\n",ans);
    return 0;
}

