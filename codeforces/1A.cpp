#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
int n,m,a;
int main()
{
    scanf("%d%d%d",&n,&m,&a);
    LL ans=(LL)ceil((double)n/a)*(LL)ceil((double)m/a);
    cout<<ans<<endl;
    return 0;
}
