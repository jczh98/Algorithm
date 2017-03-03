#include <cstdio>
#define M 10001
typedef long long LL;
LL num[10000];
int n,ans[10000];
void ExGcd(LL a,LL b,LL &g,LL &x,LL &y)
{
    if(b==0)g=a,x=1,y=0;
    else {ExGcd(b,a%b,g,y,x);y-=x*(a/b);}
}
int check(LL a,LL b)
{
    ans[1]=num[1];
    for(int i=2;i<=2*n;i++)
    {
        ans[i]=(a*ans[i-1]+b)%M;
    }
    for(int i=1;i<=2*n;i+=2)
    {
        if(ans[i]!=num[(i/2)+1])return 0;
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&num[i]);
    for(int a=0;a<=10000;a++)
    {
        LL b,k,g;
        ExGcd(a+1,M,g,b,k);
        LL t=(num[2]-a*a*num[1]);
        if(t%g)continue;
        b=b*t/g;
        if(check(a,b))
        {
            for(int i=2;i<=2*n;i+=2)
            {
                printf("%d\n",ans[i]);
            }
            break;
        }
    }
    return 0;
}
