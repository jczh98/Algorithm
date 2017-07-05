#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
int t,x_1,y_1,r_1,x_2,y_2,r_2;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&x_1,&y_1,&r_1,&x_2,&y_2,&r_2);
        double dis=sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
        if(dis>=r_1+r_2)printf("0.000000\n");
        else
        {
            if(r_1<r_2)swap(r_1,r_2);
            if(r_1-r_2>=dis)printf("%.6f\n",pi*r_2*r_2);
            else
            {
                double theta2=acos((r_2*r_2+dis*dis-r_1*r_1)/2.0/r_2/dis);
                double theta1=acos((r_1*r_1+dis*dis-r_2*r_2)/2.0/r_1/dis);
                printf("%.6f\n",theta2*r_2*r_2+theta1*r_1*r_1-sin(theta1)*r_1*dis);
            }
        }
    }
    return 0;
}
