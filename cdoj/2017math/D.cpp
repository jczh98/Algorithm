#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL r[100],primes[100],ans,mx=-1;
LL Exgcd(LL a,LL b,LL &x,LL &y)
{
    LL d;
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    d=Exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
LL ChineseRemainder(int len)
{
    LL d,x,y,m,n=1,tans;
    LL sum=0;
    for(int i=1;i<=len;i++)n*=primes[i];
    for(int i=1;i<=len;i++)
    {
        m=n/primes[i];
        d=Exgcd(primes[i],m,x,y);
        sum=(sum+(LL)y*(LL)m*r[i])%n;
    }
    tans=(n+sum%n)%n;
    if(tans<mx)tans+=n*(int)ceil((double)(mx-tans)/n);
    return tans;
}
int main()
{
    for(int i=1;i<=6;i++)cin>>primes[i];
    for(int i=1;i<=6;i++)cin>>r[i],mx=max(r[i],mx);
    LL ans=ChineseRemainder(6);
    cout<<ans<<endl;
    return 0;
}

