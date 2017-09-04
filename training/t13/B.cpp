#include <bits/stdc++.h>
using namespace std;
int t,n,s,rem,mx_num[300],flag=0,min_num[300];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&s);
        if(9*n<s||(n>=2&&s==0))
        {
            printf("-1 -1\n");
            continue;
        }
        rem=s;
        for(int i=1;i<=n;i++)
        {
            if(rem-9>=0)
            {
                mx_num[i]=9;
                rem-=9;
            }else
            {
                mx_num[i]=rem;
                rem-=rem;
            }
        }
        min_num[1]=1;
        rem=s-1;
        for(int i=n;i>=2;i--)
        {
            if(rem-9>=0)
            {
                min_num[i]=9;
                rem-=9;
            }else
            {
                min_num[i]=rem;
                rem-=rem;
            }
        }
        min_num[1]+=rem;
        for(int i=1;i<=n;i++)
        {
            printf("%d",min_num[i]);
        }
        printf(" ");
        for(int i=1;i<=n;i++)
        {
            printf("%d",mx_num[i]);
        }
        printf("\n");
    }
    return 0;
}
