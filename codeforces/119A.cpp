#include <cstdio>
#include <cstring>
int Gcd(int a,int b)
{
    if(b==0)return a;
    return Gcd(b,a%b);
}
int a,b,n,re,ans=1;
int main()
{
    scanf("%d%d%d",&a,&b,&n);
    re=n;
    while(true)
    {
        int g;
        if(ans>0)g=Gcd(a,re);else g=Gcd(b,re);
        if(g>re)break;
        re-=g;ans*=-1;

    }
    if(ans<0)printf("0\n");
    else printf("1\n");
    return 0;
}
