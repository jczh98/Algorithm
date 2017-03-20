#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,s[1000010],cnt[10],ans=0;
int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]),cnt[s[i]]++;
    ans+=cnt[4];
    int a=min(cnt[1],cnt[3]);
    ans+=a;cnt[1]-=a;cnt[3]-=a;
    if(cnt[1]<0)cnt[1]=0;if(cnt[3]<0)cnt[3]=0;
    ans+=cnt[3];
    ans+=cnt[2]/2;cnt[2]%=2;
    if(cnt[2]==1)
    {
        if(cnt[1]<=2)ans+=1,cnt[1]=0;
        else
        {
            ans+=1;cnt[1]-=2;
        }
    }
    ans+=cnt[1]/4;cnt[1]%=4;
    if(cnt[1])ans++;
    printf("%d\n",ans);
    return 0;
}
