#include <bits/stdc++.h>
#define MN 200
using namespace std;
int n,a[MN],flag1=0,mx1=0,mx1_pos=0,mx2=0,mx2_pos=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i+1])
        {
            flag1=1;break;
        }
    }
    if(!flag1)
    {
        printf("Yes\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(mx1<a[i])
        {
            mx1=a[i];
            mx1_pos=i;
        }
    }
    for(int i=mx1_pos;i<=n;i++)
    {
        if(a[i]==mx1)
        {
            mx2_pos=i;
        }else break;
    }
    for(int i=1;i<mx1_pos;i++)
    {
        if(a[i]>=a[i+1])
        {
            printf("NO\n");
            return 0;
        }
    }
    for(int i=mx2_pos+1;i<n;i++)
    {
        if(a[i]<=a[i+1])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
