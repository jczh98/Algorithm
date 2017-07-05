#include <bits/stdc++.h>
using namespace std;
int n,l1,l2,a1,a2,l_t,a_t,cnt,ans1,ans2;
int Gcd(int a,int b)
{
    if(!b)return a;
    else return Gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cnt=0;ans1=ans2=0;
        scanf("%d%d%d%d%d%d",&l1,&a1,&l2,&a2,&l_t,&a_t);
        for(int j=1;l1*j<l_t;j++)
        {
            if(l_t-l1*j<0)continue;
            if((l_t-l1*j)%l2!=0)continue;
            int k=(l_t-l1*j)/l2;
            if((a1*j+a2*k)!=a_t)continue;
            ans1=j;ans2=k;cnt++;
        }
        if(cnt>1)
        {
            printf("?\n");
        }else
        {
            if(ans1==0||ans2==0)printf("?\n");
            else printf("%d %d\n",ans1,ans2);
        }
    }
    return 0;
}
