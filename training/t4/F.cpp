#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    int cnt=2,flag=1,flag2=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i%2);//printf("0");
        else
        {
            printf("%d:",i);
            if(flag)
            {
                printf("1");flag=0;
            }else
            {
                printf("%d",cnt);
                if(flag2)cnt++;else cnt--;
                if(cnt==10||cnt==1)
                {
                    if(flag2)
                    {
                        cnt=9;
                        flag2=0;
                    }else
                    {
                        cnt=2;
                        flag2=1;
                    }
                }
                flag=1;
            }
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
