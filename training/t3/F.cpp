#include <bits/stdc++.h>
#define MN 100
using namespace std;
int t,n,num[MN];
double p[MN],dead[MN][300],live[MN][300],ans[MN];
double Pow(double a,int b)
{
    double res=1.0;
    while(b)
    {
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        memset(dead,0,sizeof(dead));
        memset(live,0,sizeof(live));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%lf",&num[i],&p[i]);
        if(n==1)
        {
            printf("1.000000\n");continue;
        }
        //for(int i=1;i<=n;i++)cout<<p[i]<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=110;k++)
            {
                double t=Pow(p[i],k);
                dead[i][k]=Pow(1-t,num[i]);
                live[i][k]=1-dead[i][k];
                //cout<<live[i][k]<<endl;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=99;k++)
            {
                double other_dead=1.0;
                for(int j=1;j<=n;j++)
                {
                    if(i==j)continue;
                    other_dead*=dead[j][k];
                }
                //cout<<other_dead<<endl;
                ans[i]+=((live[i][k]-live[i][k+1])*other_dead);
            }
        }
        for(int i=1;i<n;i++)printf("%.6f ",ans[i]);printf("%.6f\n",ans[n]);
    }
    return 0;
}
