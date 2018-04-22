#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
//set<int>::iterator set_stater
//typedef pair<int,int> pii;
using namespace std;
typedef long long ll;
ll dp[100100],mod=1e9+7,pow2=4;
int main()
{
    dp[1]=dp[2]=1;
    ff(i,3,100000)
    {
        dp[i]=(dp[i-1]*(mod+pow2-1))%mod;
        pow2=(pow2*2)%mod;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",dp[n]);
    }
    return 0;
}