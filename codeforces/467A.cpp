#include <cstdio>
#include <cstring>
int ans=0,n,p,q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p,&q);
        if(q-p>=2)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
