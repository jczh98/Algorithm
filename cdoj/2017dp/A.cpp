#include <bits/stdc++.h>
using namespace std;
int n,a[100];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++)a[i]=2*i-1;
    for(int i=1;i<=n/2;i++)a[i+n/2]=n-2*(i-1);
    for(int i=1;i<=n-1;i++)
    {
        for(int i=1;i<=n/2;i++)printf("%d %d ",a[i],a[n-i+1]);printf("\n");
        int t=a[2];
        for(int i=2;i<n;i++)a[i]=a[i+1];
        a[n]=t;
    }
}

