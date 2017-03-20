#include <cstdio>
#include <cstring>
int n,m,tot=0;
int main()
{
    scanf("%d%d",&n,&m);tot=n;
    for(int i=1;i<=100000000;i++)
    {
        if(i%m==0)tot++;
        tot--;
        if(tot==0)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}
