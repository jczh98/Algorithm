#include <cstdio>
#include <cstring>
int n,m,z,cnt[100100],ans=0;
int main()
{
    scanf("%d%d%d",&n,&m,&z);
    memset(cnt,0,sizeof(cnt));
    int k=1;
    while(k*n<=z)cnt[k*n]=1,k++;
    k=1;
    while(k*m<=z)
    {
        if(cnt[k*m])ans++;
        k++;
    }
    printf("%d\n",ans);
    return 0;
}
