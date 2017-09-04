#include <bits/stdc++.h>
using namespace std;
int x_0,x_1,x_2,y_0,y_1,y_2,z_0,z_1,z_2;
long long ans=0,dis_x=0,dis_y=0,dis_z=0;
int main()
{
    scanf("%d%d%d",&x_0,&y_0,&z_0);
    scanf("%d%d%d",&x_1,&y_1,&z_1);
    scanf("%d%d%d",&x_2,&y_2,&z_2);
    if(x_0>=x_1&&x_0<=x_2&&y_0>=y_1&&y_0<=y_2&&z_0>=z_1&&z_0<=z_2)
    {
        printf("0\n");
        return 0;
    }
    if(y_0<y_1) dis_y=y_1-y_0;
    if(y_0>y_2) dis_y=y_2-y_0;

    if(x_0<x_1) dis_x=x_1-x_0;
    if(x_0>x_2) dis_x=x_2-x_0;

    if(z_0<z_1) dis_z=z_1-z_0;
    if(z_0>z_2) dis_z=z_2-z_0;

    ans=dis_x*dis_x+dis_y*dis_y+dis_z*dis_z;

    printf("%lld",ans);
    return 0;
}
