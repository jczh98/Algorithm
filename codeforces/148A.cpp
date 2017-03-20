#include <cstdio>
#include <cstring>
int k,l,m,n,d,cnt[100100],ans=0;
int main()
{
    scanf("%d%d%d%d%d",&k,&l,&m,&n,&d);
    for(int i=k;i<=d;i+=k)cnt[i]=1;
    for(int i=l;i<=d;i+=l)cnt[i]=1;
    for(int i=m;i<=d;i+=m)cnt[i]=1;
    for(int i=n;i<=d;i+=n)cnt[i]=1;
    for(int i=1;i<=d;i++)if(cnt[i])ans++;
    printf("%d\n",ans);
    return 0;
}
