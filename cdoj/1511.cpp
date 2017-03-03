#include <cstdio>
#include <iostream>
using namespace std;
int n,a;
double ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a,ans+=1.0-(1.0-a/100.0)*(1.0-a/100.0);
    printf("%.3f\n",ans);
    return 0;
}
