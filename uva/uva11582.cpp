#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
int f[1000100];
ULL a,b;
int n,t,m;
int Ksm(ULL x,ULL y,int mod)
{
    ULL r=1;ULL base=x;
    while(y)
    {
        if(y&1)r=(r%mod)*(base%mod)%mod;
        base=(base%mod)*(base%mod)%mod;
        y>>=1;
    }
    return r%mod;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
       scanf("%llu%llu%d",&a,&b,&n);f[0]=0;f[1]=1;m=1;
       if(a==0||n==1)
       {
           printf("0\n");continue;
       }else {
            for(int i=2;i<=n*n;i++)
            {
                f[i]=(f[i-1]+f[i-2])%n;
                if(f[i]==1&&f[i-1]==0)
                {
                    m=i-1;break;
                }
            }
        int k=Ksm(a%m,b,m);
        printf("%d\n",f[k]);
       }
    }
    return 0;
}
