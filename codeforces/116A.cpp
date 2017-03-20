#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans=0,a,b,cnt=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        cnt=cnt-a+b;
        ans=max(cnt,ans);
    }
    scanf("%d%d",&a,&b);
    printf("%d\n",ans);
    return 0;
}
