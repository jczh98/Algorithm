#include <bits/stdc++.h>
using namespace std;
double n,m;
int main()
{
    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);
    scanf("%lf%lf",&n,&m);
    double t=pow((n-1)/n,m);
    //printf("%.9lf\n",t);
    //printf("%.9lf\n",1.0-t);
    printf("%.11f\n",n-n*t);
    return 0;
}
