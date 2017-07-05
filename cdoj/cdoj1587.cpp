#include <bits/stdc++.h>
#define MOD 554056561
using namespace std;
int n,f[772002+10];
int main()
{
    scanf("%d",&n);
    f[1]=3;f[2]=9;
    if(n<3)printf("%d\n",f[n]);
    if(n>=3)
    {
        for(int i=3;i<=n;i++)
        {
            f[i]=2*f[i-1]+f[i-2];f[i]%=MOD;
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
