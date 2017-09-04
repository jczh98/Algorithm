#include <bits/stdc++.h>
#define MN 5000
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pLL;
char s1[MN],s2[MN];
int sum1[MN][30],sum2[MN][30],n1,n2,t[30],ans=0;
vector<pLL> hs1_val[MN];
pLL GetHash(int *v)
{
    const LL mod1=1e9+7,mod2=1e9+9;
    LL seed1=23,seed2=772002;
    LL hs1=seed1,hs2=seed2;
    for(int i=0;i<=25;i++)
    {
        hs1=(hs1*seed2+v[i])%mod1;
        hs2=(hs2*seed2+v[i])%mod2;
    }
    return make_pair(hs1,hs2);
}
int main()
{
    scanf("%s%s",s1,s2);
    n1=strlen(s1);n2=strlen(s2);
    for(int i=0;i<n1;i++)
    {
        memcpy(sum1[i],sum1[i-1],sizeof(sum1[i]));
        sum1[i][s1[i]-'a']++;
    }
    for(int i=0;i<n2;i++)
    {
        memcpy(sum2[i],sum2[i-1],sizeof(sum2[i]));
        sum2[i][s2[i]-'a']++;
    }
    for(int len=1;len<=min(n1,n2);len++)
    {
        for(int i=0;i+len-1<n1;i++)
        {
            int t[30];
            for(int j=0;j<=25;j++)
            {
                t[j]=sum1[i+len-1][j]-sum1[i-1][j];
            }
            hs1_val[len].push_back(GetHash(t));
        }
        for(int i=0;i+len-1<n2;i++)
        {
            int t[30];
            for(int j=0;j<=25;j++)
            {
                t[j]=sum2[i+len-1][j]-sum2[i-1][j];
            }
            if(find(hs1_val[len].begin(),hs1_val[len].end(),GetHash(t))!=hs1_val[len].end())
            {
                ans=len;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
