#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,number[100];
LL n,dp[100][10];
LL Dfs(int pos,int pre,int state,int limit)
{
    if(pos==-1)return 1;
    if(!limit&&dp[pos][state]!=-1)return dp[pos][state];
    int up=limit?number[pos]:9;
    LL t=0;
    for(int i=0;i<=up;i++)
    {
        if(pre==1&&i==3)continue;
        t+=Dfs(pos-1,i,i==1,limit&&i==number[pos]);
    }
    if(!limit)dp[pos][state]=t;
    return t;
}
LL Solve(LL x)
{
    int pos=0;
    while(x)
    {
        number[pos++]=x%10;
        x/=10;
    }
    return Dfs(pos-1,-1,0,true)-1;
}
int main()
{
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    memset(dp,-1,sizeof(dp));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        LL l=1,r=(LL)2*1e18,mid,cnt;
        while(l<r)
        {
            mid=(l+r)/(LL)2;
            cnt=Solve(mid);
            if(cnt>=n)
            {
                r=mid;
            }else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
