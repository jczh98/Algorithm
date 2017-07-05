#include <bits/stdc++.h>
#define MN 1010
#define pi acos(-1.0)
using namespace std;
struct Point
{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator < (const Point &rhs) const {return x<rhs.x||(x==rhs.x&&y<rhs.y);}
    Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y);}
    int operator ^ (const Point &rhs) const {return x*rhs.y-y*rhs.x;}
}a[MN],p[MN];
double Length(Point a,Point b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
int n,l;
double ans=0.0;
int ConvexHull()
{
    sort(a+1,a+1+n);
    int top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>1&&((p[top]-p[top-1])^(a[i]-p[top-1]))<=0)top--;
        p[++top]=a[i];
    }
    int k=top;
    for(int i=n-1;i>=1;i--)
    {
        while(top>k&&((p[top]-p[top-1])^(a[i]-p[top-1]))<=0)top--;
        p[++top]=a[i];
    }
    return top-1;
}
int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
    int m=ConvexHull();
    for(int i=1;i<m;i++)ans+=Length(p[i],p[i+1]);
    ans+=Length(p[1],p[m]);
    ans+=2.0*pi*l;
    printf("%d\n",(int)(ans+0.5));
    return 0;
}

