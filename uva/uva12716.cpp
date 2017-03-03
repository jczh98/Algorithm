#include <cstdio>
#include <cstring>
#define MN 30000000
int n,t,ans[MN+10];
void Init()
{
    memset(ans,0,sizeof(ans));
    for(int c=1;c<=(MN>>1);c++)
    {
        for(int a=c*2;a<=MN;a+=c)
        {
            if((a^(a-c))==c)ans[a]++;
        }
    }
    for(int i=2;i<=MN;i++)ans[i]+=ans[i-1];
}
int main()
{
    Init();
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        printf("Case %d: ",i);
        printf("%d\n",ans[n]);
    }
    return 0;
}
