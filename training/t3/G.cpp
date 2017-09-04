#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL f[200][200];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(j>=i)f[i][j]=f[i-1][j]+f[i][j-i];
                else f[i][j]=f[i-1][j];
            }
        }
        printf("%lld\n",f[n][n]);
    }
    return 0;
}
