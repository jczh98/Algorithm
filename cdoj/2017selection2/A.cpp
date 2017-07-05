#include <bits/stdc++.h>
using namespace std;
int t,n,a[100],sum,mx,mxi,flag;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);sum=0;mx=-100;mxi=0;flag=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
        for(int i=1;i<=n;i++)if(mx<a[i])mx=a[i],mxi=i;
        for(int i=1;i<=n;i++)if(mx==a[i]&&(i!=mxi))flag=1;
        if(flag)printf("no winner\n");
        else
        {
            if(mx>sum/2)printf("majority winner %d\n",mxi);
            else printf("minority winner %d\n",mxi);
        }
    }
    return 0;
}
