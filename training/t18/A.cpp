#include <bits/stdc++.h>
using namespace std;
int t,cnt,fac[1000];
double ans,cur,p;
char number[10000];
int main()
{
    fac[0]=1;
    for(int i=1;i<=10;i++)fac[i]=fac[i-1]*i;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;ans=0.0;
        scanf("%s",&number);
        int len=strlen(number);
        while(next_permutation(number,number+len)) cnt++;
        p=1.0/fac[len];
        if(cnt)
        {
            ans=cur=p;
            for(int i=1;i<cnt;i++)
            {
                cur=ans+ans*p;
                ans=cur;
            }
        }
        printf("%.9f\n",ans);
    }
    return 0;
}
