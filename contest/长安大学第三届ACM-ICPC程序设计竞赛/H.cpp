#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
/ t<int>::iterator set_stater
/ pedef pair<int,int> pii;
using namespace std;
typedef long long ll;
ll dp[2][3100],n,p,m;
typedef struct node
{
    ll val,ab,id;
};
node mes[2200];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(dp,0,sizeof(dp));
        ll sta=0,sum=0,ans=0,mon=0;
        ff(i,1,n)
        {
            scanf("%lld%lld",&mes[i].ab,&mes[i].val);
            mes[i].id=1;
            sum+=mes[i].ab;
            mon+=mes[i].val;
        }
        scanf("%lld",&m);
        ff(i,1,m)
        {
            scanf("%lld%lld",&mes[i+n].ab,&mes[n+i].val);
            mes[i+n].id=0;
        }
        scanf("%lld",&p);mon+=p;
        dp[0][p]=sum;
        ff(i,1,m+n)
        {
            sta^=1;
            memset(dp[sta],-1,sizeof(dp[sta]));
            ff(j,0,mon)
            {
                if(i<=n)
                {
                    dp[sta][j]=max(dp[sta][j],dp[1-sta][j]);
                    if(j>=mes[i].val)
                    dp[sta][j]=max(dp[sta][j],dp[1^sta][j-mes[i].val]-mes[i].ab);
                }
                else
                {
                    dp[sta][j]=max(dp[sta][j],dp[1-sta][j]);
                    if(dp[1^sta][j+mes[i].val]==-1)
                        continue;
                    dp[sta][j]=max(dp[sta][j],dp[1^sta][j+mes[i].val]+mes[i].ab);
                }
            }
        }
        ff(i,0,mon)
        ans=max(ans,dp[sta][i]);
        printf("%lld\n",ans);
    }
    return 0;
}