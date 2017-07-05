#include <cstdio>
#include <cmath>
#define eps 1e-10
using namespace std;
int t,x1,y_1,z1,vx1,vy1,vz1,r1,x2,y2,z2,vx2,vy2,vz2,r2,a,b,c,r;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d%d",&x1,&y_1,&z1,&r1,&vx1,&vy1,&vz1);
        scanf("%d%d%d%d%d%d%d",&x2,&y2,&z2,&r2,&vx2,&vy2,&vz2);
        a=(vx1-vx2)*(vx1-vx2)+(vy1-vy2)*(vy1-vy2)+(vz1-vz2)*(vz1-vz2);
        b=(x1-x2)*(vx1-vx2)+(y_1-y2)*(vy1-vy2)+(z1-z2)*(vz1-vz2);b*=2;
        c=(x1-x2)*(x1-x2)+(y_1-y2)*(y_1-y2)+(z1-z2)*(z1-z2);
        r=r1+r2;
        if(!a)printf("No collision\n");
        else
        {
            double t=-b*1.0/2.0/(double)a,d2;
            if(t<=0.0)d2=c;else d2=(double)a*t*t+(double)b*t+c;
            if(d2>r*r+eps)printf("No collision\n");
            else
            {
                double ans=(-b*1.0-sqrt(b*b*1.0-4.0*a*(c-r*r)))/2.0/(double)a,ans2=(-b*1.0+sqrt(b*b*1.0-4.0*a*(c-r*r)))/2.0/(double)a;
                if(ans<0)ans=ans2;printf("%.3f\n",ans);
            }
        }
    }
    return 0;
}
