#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[10000],tot=0,cnt=0,ans=0;
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),tot+=a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        cnt+=a[i];ans++;
        if(2*cnt>tot) break;
    }
    printf("%d\n",ans);
    return 0;
}
