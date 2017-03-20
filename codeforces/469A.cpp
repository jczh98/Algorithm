#include <cstdio>
#include <cstring>
int n,p,q,x,cnt[100000];
int main()
{
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    scanf("%d",&p);
    for(int i=1;i<=p;i++)scanf("%d",&x),cnt[x]=1;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)scanf("%d",&x),cnt[x]=1;
    for(int i=1;i<=n;i++)if(cnt[i]==0)
    {
        printf("Oh, my keyboard!\n");
        return 0;
    }
    printf("I become the guy.\n");
    return 0;
}
