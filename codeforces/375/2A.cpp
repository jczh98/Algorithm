#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[100],dis,ans=(1<<30);

int main()
{
    scanf("%d%d%d",&a[1],&a[2],&a[3]);
    sort(a+1,a+4);
    for(int i=a[1];i<=a[3];i++)
    {
        dis=0;
        for(int j=1;j<=3;j++)
        {
            dis+=fabs(a[j]-i);
        }
        if(dis<ans)ans=dis;
    }
    printf("%d\n",ans);
    return 0;
}
