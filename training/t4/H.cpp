#include <bits/stdc++.h>
using namespace std;
int k,n,m;
int main()
{
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d%d",&n,&m);
        if(n==1||m==1)
        {
            printf("No\n");
            continue;
        }
        if((n%2)&&(m%2))printf("No\n");
        else if(!(n%2)&&m%2)
        {
            if(m%3==0)
            {
                printf("Yes\n");
            }else
            {
                if(n%3==0)printf("Yes\n");
                else printf("No\n");
            }
        }else if(!(m%2)&&(n%2))
        {
            if(n%3==0)
            {
                printf("Yes\n");
            }else
            {
                if(m%3==0)printf("Yes\n");
                else printf("No\n");
            }
        }else
        {
            if(n%3==0||m%3==0)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
