#include <bits/stdc++.h>
using namespace std;
int n,a[100000];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    printf("%d\n",a[n]-a[1]);
    return 0;
}
