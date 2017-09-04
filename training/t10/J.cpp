#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pLL;
int n;
char alice[1000000],bob[1000000];
map<pLL,int> mp;
pLL hs1[1000000],hs2[1000000];
LL seed=23,mod1=1e9+7,mod2=1e9+9,ans=0,t=0;
LL QuickPow(LL a,LL b,LL mod)
{
    LL res=1;
    while(b)
    {
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    scanf("%s%s",alice,bob);
    int len1=strlen(alice),len2=strlen(bob);
    int cnt=0;
    for(int i=0;i<len1;i++)
    {
        if(alice[i]=='('||alice[i]==',')continue;
        if(isdigit(alice[i]))
        {
            cnt++;
            LL t1=alice[i]-'0';
            while(isdigit(alice[i+1]))
            {
                t1=t1*10+alice[i+1]-'0';
                i++;
            }
            hs1[cnt].first=QuickPow(seed,t1,mod1);
            hs1[cnt].second=QuickPow(seed,t1,mod2);
            mp[hs1[cnt]]=1;
        }
        if(alice[i]==')')
        {
            cnt--;
            hs1[cnt].first=(hs1[cnt].first+hs1[cnt+1].first)%mod1;
            hs1[cnt].second=(hs1[cnt].second+hs1[cnt+1].second)%mod2;
            mp[hs1[cnt]]=1;
        }
    }
    cnt=0;
    for(int i=0;i<len2;i++)
    {
        if(bob[i]=='('||bob[i]==',')continue;
        if(isdigit(bob[i]))
        {
            cnt++;
            LL t1=bob[i]-'0';
            while(isdigit(bob[i+1]))
            {
                t1=t1*10+bob[i+1]-'0';
                i++;
            }
            hs2[cnt].first=QuickPow(seed,t1,mod1);
            hs2[cnt].second=QuickPow(seed,t1,mod2);
            if(mp.count(hs2[cnt]))ans++;
        }
        if(bob[i]==')')
        {
            cnt--;
            hs2[cnt].first=(hs2[cnt].first+hs2[cnt+1].first)%mod1;
            hs2[cnt].second=(hs2[cnt].second+hs2[cnt+1].second)%mod2;
            if(mp.count(hs2[cnt]))ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
