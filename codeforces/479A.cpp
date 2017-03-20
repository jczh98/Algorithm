#include <cstdio>
#include <algorithm>
using namespace std;
int a,b,c,ans=0;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    ans=max(ans,a+b+c);
    ans=max(ans,a*b*c);
    ans=max(ans,a+(b*c));
    ans=max(ans,a*b+c);
    ans=max(ans,(a+b)*c);
    ans=max(ans,a*(b+c));
    printf("%d\n",ans);
    return 0;
}
