#include <bits/stdc++.h>
using namespace std;
struct Seg
{
    int x_1,y_1,x_2,y_2;
}seg[5050];
int n,ans=0;
bool Check(int x,int y)
{
    if(seg[x].x_1==seg[y].x_1&&seg[x].y_1==seg[y].y_1)return true;
    if(seg[x].x_1==seg[y].x_2&&seg[x].y_1==seg[y].y_2)return true;
    if(seg[x].x_2==seg[y].x_1&&seg[x].y_2==seg[y].y_1)return true;
    if(seg[x].x_2==seg[y].x_2&&seg[x].y_2==seg[y].y_2)return true;
    return false;
}
bool Judge(int x,int y)
{
    if(Check(x,y))
    {
        //cout<<x<<" "<<y<<endl;
        int up_x=seg[x].y_1-seg[x].y_2;
        int down_x=seg[x].x_1-seg[x].x_2;
        int up_y=seg[y].y_1-seg[y].y_2;
        int down_y=seg[y].x_1-seg[y].x_2;
        if(up_x==0)
        {
            if(down_y==0)return true;
            else return false;
        }
        if(up_y==0)
        {
            if(down_x==0)return true;
            else return false;
        }
        if(down_x==0)
        {
            if(up_y==0)return true;
            else return false;
        }
        if(down_y==0)
        {
            if(up_x==0)return true;
            else return false;
        }
        if(up_y*up_x+down_x*down_y==0)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("lshape.in","r",stdin);
    freopen("lshape.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&seg[i].x_1,&seg[i].y_1,&seg[i].x_2,&seg[i].y_2);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(Judge(i,j))
            {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
