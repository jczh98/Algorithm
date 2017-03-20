#include <cstdio>
int w;
int main()
{
    scanf("%d",&w);
    for(int i=1;i<=w/2;i++)if(!(i%2)&&!((w-i)%2))
    {
        printf("YES");
        return 0;
    }
    printf("NO\n");
    return 0;
}
