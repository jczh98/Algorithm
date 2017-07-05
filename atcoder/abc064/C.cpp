#include <bits/stdc++.h>
using namespace std;
int n,a[100000],c[10],cnt=0,minans=0,maxans=0;
int main()
{
    memset(c,0,sizeof(c));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=1&&a[i]<=399)
        {
            c[1]=1;
        }else if(a[i]>=400&&a[i]<=799)
        {
            c[2]=1;
        }else if(a[i]>=800&&a[i]<=1199)
        {
            c[3]=1;
        }else if(a[i]>=1200&&a[i]<=1599)
        {
            c[4]=1;
        }else if(a[i]>=1600&&a[i]<=1999)
        {
            c[5]=1;
        }else if(a[i]>=2000&&a[i]<=2399)
        {
            c[6]=1;
        }else if(a[i]>=2400&&a[i]<=2799)
        {
            c[7]=1;
        }else if(a[i]>=2800&&a[i]<=3199)
        {
            c[8]=1;
        }else
        {
            cnt++;
        }
    }
    int flag=0;
    for(int i=1;i<=8;i++)
    {
        if(!c[i])flag++;
    }
    for(int i=1;i<=8;i++)
    {
        if(c[i])minans++;
    }
    maxans=minans+cnt;
    if(flag==8)minans=1,maxans=cnt;
    printf("%d %d\n",minans,maxans);
    return 0;
}
