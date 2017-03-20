#include <cstdio>
#include <cstring>
#include <cmath>
int n,a[13]={4,7,44,47,74,77,444,447,477,744,747,774,777};
int main()
{
    scanf("%d",&n);
    int t=n,f=0;
    for(int i=0;i<13;i++)
    {
        if(n%a[i]==0)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
