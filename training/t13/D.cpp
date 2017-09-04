#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int t,n,kase=1;
double R;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%d",&R,&n);
        double ans=R/(1.0+1/sin(pi/(double)n));
        printf("Case %d: %.10f\n",kase++,ans);
    }
    return 0;
}
