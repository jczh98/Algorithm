#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,a[200100];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=(n/2);i++)if(i%2!=0)swap(a[i],a[n-i+1]);
    for(int i=1;i<n;i++)printf("%d ",a[i]);printf("%d\n",a[n]);
    return 0;
}
