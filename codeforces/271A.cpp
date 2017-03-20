#include <cstdio>
#include <cstring>
#include <cmath>
int n,cnt[20];
int main()
{
    scanf("%d",&n);
    for(int i=n+1;i<=9999;i++)
    {
        int t=i,f=0;
        memset(cnt,0,sizeof(cnt));
        while(t)
        {
            cnt[t%10]++;t/=10;
        }
        for(int j=0;j<=9;j++)if(cnt[j]>1)
        {
            f=1;break;
        }
        if(f)continue;
        else
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
