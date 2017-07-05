#include <bits/stdc++.h>
using namespace std;
int n,l,v1,v2,k;
int main()
{
    while(scanf("%d%d%d%d%d",&n,&l,&v1,&v2,&k)!=EOF)
    {
        int cnt=ceil((double)n/k);
        double l1=(double)l*(double)(v1+v2)/(double)((2*cnt-1)*v1+v2);
        double t=l1/(double)v2+((double)l-l1)/(double)v1;
        printf("%.10f\n",t);
    }
    return 0;
}
