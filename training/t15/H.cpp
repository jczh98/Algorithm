#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
int n,m;
LL C[100][100],fac[200],ans=0,p=1;
/*int main()
{
    C[1][0]=C[1][1]=1;
    for(int i=2;i<=50;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=50;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1]);
    }
    cin>>n>>m;
    fac[0]=1;
    for(int i=1;i<=n+m;i++)fac[i]=(fac[i-1]%MOD*i%MOD)%MOD;
    for(int i=1;i<=m;i++)
    {
        ans=(ans+p*C[m][i]%MOD*fac[n+m-i]%MOD)%MOD;p*=-1;
    }
    cout<<(fac[n+m]-ans+MOD)%MOD<<endl;
    return 0;
}*/
class DerangementsDiv2
{
public:
     int count(int n, int m)
     {
        C[1][0]=C[1][1]=1;
        for(int i=2;i<=50;i++)
        {
            C[i][0]=1;
            for(int j=1;j<=50;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
        }
        fac[0]=1;
        for(int i=1;i<=n+m;i++)fac[i]=(fac[i-1]%MOD*i%MOD)%MOD;
        for(int i=1;i<=m;i++)
        {
            ans=(ans+p*C[m][i]%MOD*fac[n+m-i]%MOD)%MOD;p*=-1;
        }
        return (fac[n+m]-ans+MOD)%MOD;
     }
};
