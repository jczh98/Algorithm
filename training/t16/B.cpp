#include <bits/stdc++.h>
using namespace std;
int m,n,customer[20],trash[20],ans;
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m==0&&n==0)break;
        ans=0;
        for(int i=1;i<=m;i++)scanf("%d",&customer[i]);
        for(int i=1;i<=n;i++)
        {
            for(int i=1;i<=m;i++)scanf("%d",&trash[i]);
            for(int i=1;i<=m;i++)
            {
                if(trash[i]>customer[i]){ans++;break;}
            }
        }
        printf("%d\n",n-ans);
    }
}
