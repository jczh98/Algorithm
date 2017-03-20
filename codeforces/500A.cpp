#include <cstdio>
#include <cstring>
int n,t,a[1000000],x;
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n-1;i++)scanf("%d",&x),a[i]=i+x;
    for(int i=1;a[i]<=t;i=a[i])if(a[i]==t)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}
