#include <cstdio>
using namespace std;
int t,n,m;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%d %d\n",(m-2*n)/2,(4*n-m)/2);
    }
    return 0;
}
