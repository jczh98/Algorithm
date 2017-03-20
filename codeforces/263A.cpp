#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int ans=0,a;
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            scanf("%d",&a);
            if(a)ans=abs(i-3)+abs(j-3);
        }
    }
    printf("%d\n",ans);
    return 0;
}
