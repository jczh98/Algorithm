#include <cstdio>
int n,k,m,a,cnt=0;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&m);
        int x=1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a);
            if(a==x)cnt++,x++;
        }
    }
    printf("%d\n",2*n-k-2*cnt+1);
    return 0;
}
