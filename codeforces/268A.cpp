#include <cstdio>
#include <cstring>
int n,h[1000],a[1000],ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&h[i],&a[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            if(h[i]==a[j])ans++;
    }
    printf("%d\n",ans);
    return 0;
}
