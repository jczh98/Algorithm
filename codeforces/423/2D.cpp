#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(k==2)
    {
        printf("%d\n",n-1);
    }else if(n%k==1)
    {
        printf("%d\n",n/k*2);
    }else if(n%k==2)
    {
        printf("%d\n",n/k*2+1);
    }else
    {
        printf("%d\n",(n-1)/k*2+2);
    }
    for(int i=2;i<=k+1;i++)
    {
        printf("%d %d\n",1,i);
    }
    for(int i=k+2;i<=n;i++)
    {
        printf("%d %d\n",i-k,i);
    }
    return 0;
}
