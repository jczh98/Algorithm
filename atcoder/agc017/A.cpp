#include <bits/stdc++.h>
#define MN 100
using namespace std;
typedef long long LL;
int n,p,a[MN],even=0,odd=0;
LL ans=0,C[100][100]={0};
int main()
{
    C[0][0]=1;
    for (int i=1;i<=52;i++)
    {
        C[i][0]=1;
        for (int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1]);
    }
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2)odd++;else even++;
    }
    LL pow2=1;
    for(int i=0;i<even;i++)pow2=pow2<<1;
    if(p==1)
    {
        LL pre=0;
        for(int i=1;i<=odd;i+=2)
        {
            pre=pre+C[odd][i];
        }
        LL ans=pre*pow2;
        cout<<ans<<endl;
    }else
    {
        LL pre=0;
        for(int i=0;i<=odd;i+=2)
        {
            pre=pre+C[odd][i];
        }
        LL ans=pre*pow2;
        cout<<ans<<endl;
    }
    return 0;
}
