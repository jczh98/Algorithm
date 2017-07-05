#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        n-=3;
        int flag=0;
        if(n&&n<4)
        {
            printf("No such base\n");
            continue;
        }else if(!n)
        {
            printf("4\n");
            continue;
        }
        int i;
        for(i=4;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            if(n%3==0&&n/3>=4)
                printf("%d\n",n/3);
            else if(n%2==0&&n/2>=4)
                printf("%d\n",n/2);
            else
                printf("%d\n",n);
        }else
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
