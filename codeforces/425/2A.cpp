#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k;
int main()
{
    cin>>n>>k;
    LL t=n/k;
    if(t&1)printf("YES\n");else printf("NO\n");
    return 0;
}
