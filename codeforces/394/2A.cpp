#include <cstdio>
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    if(a==0&&b==0)
    {
        printf("NO\n");
        return 0;
    }
    int t1=a,t2=b;
    for(int i=1;i<=(a+b);i++)
    {
        if(i%2==0)t1--;
        else t2--;
    }
    if(t1==0&&t2==0)
    {
        printf("YES\n");return 0;
    }
    t1=a;t2=b;
    for(int i=2;i<=(a+b+1);i++)
    {
        if(i%2==0)t1--;
        else t2--;
    }
    if(t1==0&&t2==0)
    {
        printf("YES\n");return 0;
    }
    printf("NO\n");return 0;
}
