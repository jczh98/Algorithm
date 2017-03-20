#include <cstdio>
#include <cstring>
#include <cmath>
int a,b,re=0,ans=0;
int main()
{
    scanf("%d%d",&a,&b);
    re=a;ans+=re;
    while(re>=b)
    {
        ans+=re/b;
        re=re-(re/b)*b+re/b;
    }
    printf("%d\n",ans);
    return 0;
}
