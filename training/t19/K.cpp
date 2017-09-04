#include <iostream>
#include <stdio.h>
#define MAXN 10000
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
LL t,n,k,fac[MAXN+10],inv[MAXN+10],D[MAXN+10],ans;
LL QuickPow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1)res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}
int main()
{
    cin>>t;
    fac[0]=1;
    for(int i=1;i<=MAXN;i++)fac[i]=(fac[i-1]*i)%MOD;
    inv[MAXN]=QuickPow(fac[MAXN],MOD-2);
    for(int i=MAXN-1;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%MOD;
    D[0]=1;D[1]=0;D[2]=1;
    for(int i=3;i<=MAXN;i++)D[i]=(i-1)*(D[i-1]+D[i-2])%MOD;
    while(t--)
    {
        cin>>n>>k;ans=0;
        for(int i=k;i<=n;i++)
        {
            ans=(ans+fac[n]%MOD*inv[n-i]%MOD*inv[i]%MOD*D[n-i]%MOD)%MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
