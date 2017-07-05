#include <bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
typedef long long LL;
char str[200200];
int cnt[200200][2]={0};
LL fac[400500],inv[400500],ans=0;
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
void Pre()
{
    fac[0]=1;int N=400400;
    for(int i=1;i<=N;i++)fac[i]=(fac[i-1]*i)%MOD;
    inv[N]=QuickPow(fac[N],MOD-2);
    for(int i=N-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%MOD;
}
int main()
{
    Pre();
    scanf("%s",str);
    int cnt0=0,cnt1=0,len=strlen(str),mx;
    for(int i=0;i<len;i++)
    {
        if(str[i]=='0')cnt0++;cnt[i][0]=cnt0;
        if(str[i]=='1')cnt1++;cnt[i][1]=cnt1;
    }
    for(int i=0;i<len;i++)
    {
        if(str[i]=='1')continue;
        int l=cnt[i][0],r=cnt[len-1][1]-cnt[i][1];
        ans+=(((fac[l+r])%MOD*(inv[l])%MOD*(inv[r])%MOD)%MOD-((fac[l+r-1])%MOD*(inv[l-1])%MOD*(inv[r])%MOD)%MOD+MOD)%MOD;
    }
    printf("%lld",(ans+MOD)%MOD);
    return 0;
}
