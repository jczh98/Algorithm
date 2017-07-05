#include <bits/stdc++.h>
using namespace std;
int n,a[100100],mx=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)mx=max(mx,a[i]+n-i+1);
    mx++;printf("%d\n",mx);
    return 0;
}
