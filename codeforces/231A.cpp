#include<cstdio>
#include <iostream>
#include <cstring>
int n,ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=3;j++)
        {
            int a;
            scanf("%d",&a);if(a==1)cnt++;
        }
        if(cnt>=2)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
