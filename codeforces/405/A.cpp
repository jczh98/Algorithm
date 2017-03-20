#include <cstdio>
#include <cstring>
#include <iostream>
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    int ans=1,x=a,y=b;
    while(1)
    {
        x*=3;y*=2;
        if(x>y)
        {
            printf("%d\n",ans);
            break;
        }
        ans++;
    }
    return 0;
}
