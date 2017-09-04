#include <bits/stdc++.h>
#define MN 10000000+10
using namespace std;
typedef long long LL;
const LL MOD=1LL<<32;

unsigned int n,query,x0,x1,a,b,c,t;

unsigned int next() {
    t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

LL num[MN],ans=0,pre=1;
int main()
{
    cin>>n>>query>>x0>>x1>>a>>b>>c;
    for(int i=1;i<=n;i++)num[i]=1LL<<32-1;
    LL cur,x,mini=1LL<<32-1;
    for(int i=1;i<=query;i++)
    {
        pre=(pre*10099)%MOD;
        cur=next()%n;x=next();
        if(num[cur+1]==mini)
        {
            num[cur+1]=x;
            mini=1LL<<32-1;
            for(int i=1;i<=n;i++)mini=min(mini,num[i]);
        }else
        {
            num[cur+1]=x;
            if(mini>x)
            {
                mini=x;
            }
        }
        ans=(ans+mini*pre%MOD)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
