#include <bits/stdc++.h>
#define N 10010
using namespace std;
struct point{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    bool operator < (const point &c) const { return x<c.x || (x==c.x && y<c.y); }
    point operator - (const point &c) const { return point(x-c.x,y-c.y); }
    double operator * (const point &c) const { return x*c.y-y*c.x; }
    double operator | (const point &c) const { return (x-c.x)*(x-c.x)+(y-c.y)*(y-c.y); }
}a[N],b[N],p[N],q[N];
int n;
int convex_hull(point a[],point p[],int tot)
{
    sort(a+1,a+1+tot);
    int top=0;
    for(int i=1;i<=tot;i++)
    {
        while(top>1 && (p[top]-p[top-1])*(a[i]-p[top-1])<=0) top--;
        p[++top]=a[i];
    }
    int k=top;
    for(int i=tot-1;i>=1;i--)
    {
        while(top>k && (p[top]-p[top-1])*(a[i]-p[top-1])<=0) top--;
        p[++top]=a[i];
    }
    return top-1;
}
double rotating_calipers(point p[],int top)
{
    double ans=0;
    p[top+1]=p[1];
    int now=2;
    for(int i=1;i<=top;i++)
    {
        while((p[i+1]-p[i])*(p[now]-p[i])<(p[i+1]-p[i])*(p[now+1]-p[i]))
        {
            now++;
            if(now==top+1) now=1;
        }
        ans=min(ans,(p[now]|p[i]));
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
        for(int i=1;i<=m;i++)scanf("%lf%lf",&b[i].x,&b[i].y);
        int top1=convex_hull(a,p,n);
        int top2=convex_hull(b,q,m);
        printf("%f",sqrt(rotating_calipers(p,top)));
    }

    return 0;
}

