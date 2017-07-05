#include <bits/stdc++.h>
#define MN 100100
using namespace std;
int n,x0;
struct Seg
{
    int x1,y1,x2,y2,mxy,dir;
}seg[MN];
int cmp(Seg x,Seg y)
{
    return x.mxy>y.mxy;
}
int main()
{
    memset(seg,0,sizeof(seg));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&seg[i].x1,&seg[i].y1,&seg[i].x2,&seg[i].y2);
        if(seg[i].x1>seg[i].x2)swap(seg[i].x1,seg[i].x2),swap(seg[i].y1,seg[i].y2);
        seg[i].mxy=max(seg[i].y1,seg[i].y2);
        if(seg[i].y1>seg[i].y2)seg[i].dir=1;else seg[i].dir=0;
    }
    scanf("%d",&x0);
    sort(seg+1,seg+1+n,cmp);
    //for(int i=1;i<=n;i++)cout<<seg[i].x1<<" "<<seg[i].y1<<" "<<seg[i].x2<<" "<<seg[i].y2<<endl;
    for(int i=1;i<=n;i++)
    {
        if(seg[i].x1<=x0&&seg[i].x2>=x0)
        {
            //cout<<seg[i].x1<<" "<<seg[i].y1<<" "<<seg[i].x2<<" "<<seg[i].y2<<endl;
            if(seg[i].dir)x0=seg[i].x2;else x0=seg[i].x1;
        }else continue;
    }
    printf("%d\n",x0);
    return 0;
}
