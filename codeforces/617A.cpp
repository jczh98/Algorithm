#include <cstdio>
int x;
int main()
{
    scanf("%d",&x);
    printf("%d",x/5+(x%5==0?0:1));
    return 0;
}
