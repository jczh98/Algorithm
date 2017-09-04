#include <bits/stdc++.h>
using namespace std;
int t,a[100];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=20;i++)scanf("%d",&a[i]);
        for(int i=20;i>=2;i--)
        {
            if(a[i]%2)
            {
                a[i-1]+=(a[i]-1)/2;
                a[i]=1;
            }else
            {
                a[i-1]+=a[i]/2;
                a[i]=0;
            }
        }
        for(int i=1;i<20;i++)
        {
            printf("%d ",a[i]);
        }printf("%d\n",a[20]);
    }
    return 0;
}
