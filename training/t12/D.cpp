#include <bits/stdc++.h>
#define N 110
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
int t,n,kase=1;
double d[N],ans,l_bound,r_bound;
double Cal(double x)
{
    double theta=0.0;
    for(int i=1;i<=n;i++)
    {
        //t=(d[i]*d[i]+d[i+1]*d[i+1]-x*x)/2.0/d[i]/d[i+1];
        //cout<<t<<endl;
        theta+=acos((d[i]*d[i]+d[i+1]*d[i+1]-x*x)/(2.0*d[i]*d[i+1]));
    }
    return theta;
}
bool Bisection(double l,double r)
{
    while(r-l>eps)
    {
        double mid=(l+r)/2,theta=0.0;
        theta=Cal(mid);
        if(fabs(theta-2*pi)<eps)
        {
            ans=mid;
            return true;
        }
        if(theta>2*pi)r=mid;
        else l=mid;
    }
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
       l_bound=0;r_bound=20000.0;ans=0;
       scanf("%d",&n);
       for(int i=1;i<=n;i++)
       {
           scanf("%lf",&d[i]);
       }
       d[n+1]=d[1];
       for(int i=1;i<=n;i++)
       {
           r_bound=min(r_bound,d[i]+d[i+1]);
           l_bound=max(l_bound,fabs(d[i]-d[i+1]));
       }
       printf("Case %d: ",kase++);
       if(Bisection(l_bound,r_bound))
       {
           printf("%.3f\n",ans);
       }else
       {
           printf("impossible\n");
       }
    }
    return 0;
}
