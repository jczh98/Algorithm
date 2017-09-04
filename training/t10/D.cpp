#include <bits/stdc++.h>
using namespace std;
int n,ans=1;
int main()
{
    scanf("%d",&n);
    int t=1;
    while(t<n)
    {
        t*=2;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
