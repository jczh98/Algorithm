#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n,a[100000],ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int maxp=max_element(a+1,a+1+n)-a;
    for(int i=maxp;i>1;i--)swap(a[i],a[i-1]),ans++;
    reverse(a+1,a+1+n);
    int minp=min_element(a+1,a+1+n)-a;
    for(int i=minp;i>1;i--)swap(a[i],a[i-1]),ans++;
    printf("%d\n",ans);
    return 0;
}
