#include <cstdio>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
int n,m,a[100000],ans=INT_MAX;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d",&a[i]);
    sort(a+1,a+m+1);
    for(int i=1;i<=m-n+1;i++)ans=min(ans,a[i+n-1]-a[i]);
    printf("%d\n",ans);
    return 0;
}
