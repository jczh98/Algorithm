#include <cstdio>
#include <cstring>
#include <cmath>
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    if(n==1&&m==1)printf("0\n");
    else if(n==1)printf("%d\n",m/2);
    else if(m==1)printf("%d\n",n/2);
    else printf("%d\n",(n/2)*(m/2)*2+(n%2)*(m/2)+(m%2)*(n/2));
    return 0;
}
