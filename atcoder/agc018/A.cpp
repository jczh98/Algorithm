#include <bits/stdc++.h>
using namespace std;
int n,k,mx=0,a,g,flag=0;
int Gcd(int a,int b)
{
    if(a<b)swap(a,b);
    return b==0?a:Gcd(b,a%b);
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%d",&a);
    g=a;mx=a;
    if(k==a)flag=1;
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&a);
        g=Gcd(g,a);
        mx=max(mx,a);
        if(k==a)flag=1;
    }
    if(flag)
    {
        printf("POSSIBLE\n");
        return 0;
    }
    if(k>mx)
    {
        printf("IMPOSSIBLE\n");
    }else
    {
        if(k%g==0)printf("POSSIBLE\n");
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
