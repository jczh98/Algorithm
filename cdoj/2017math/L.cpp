#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7LL;
int t,n,k;
LL s[1010][1010];
int main()
{
    for(int i=0;i<=1000;i++)s[i][i]=1;
    for(int i=1;i<=1000;i++)s[i][0]=0;
    for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)s[i][j]=(j*s[i-1][j]+s[i-1][j-1])%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",s[n][k]);
    }
    return 0;
}
