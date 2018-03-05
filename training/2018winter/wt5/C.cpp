#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
const int N=1000005;
struct Point {
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator < (const Point &rhs) const {return x<rhs.x||(x==rhs.x&&y<rhs.y);}
    Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y);}
    int operator ^ (const Point &rhs) const {return x*rhs.y-y*rhs.x;}
}a[N],p[N];
struct double_point {
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y);}
    double operator ^ (const Point &rhs) const {return x*rhs.y-y*rhs.x;}
};
int n;
int convex_hull() {
    sort(a+1,a+1+n);
    int top=0;
    for(int i=1;i<=n;i++) {
        while(top>1&&((p[top]-p[top-1])^(a[i]-p[top-1]))<0)top--;
        p[++top]=a[i];
    }
    int k=top;
    for(int i=n-1;i>=1;i--) {
        while(top>k&&((p[top]-p[top-1])^(a[i]-p[top-1]))<0)top--;
        p[++top]=a[i];
    }
    return top-1;
}
double length(double_point p) {
    return sqrt(p.x*p.x+p.y*p.y);
}
int main() {
    while(scanf("%d",&n)!=EOF) {
        for(int i=1;i<=n;++i) scanf("%d%d",&a[i].x,&a[i].y);
        int m=convex_hull();
        double ans=1e9;
        cout<<endl;
        for(int i=1;i<=m;++i) {
            cout<<p[i].x<<" "<<p[i].y<<endl;
        }
        cout<<endl;
        for(int i=1;i<m;++i) {
            int dx=p[i+1].x-p[i].x,dy=p[i+1].y-p[i].y;
            cout<<dx<<" "<<dy<<endl;
            if(dx<0&&dy>0) {
                double_point p1(0,p[i].y-dy/dx*p[i].x); 
                double_point p2(p[i+1].x-dx/dy*p[i+1].y,0);
                cout<<length(p1-p2)<<endl;
                ans=min(ans,length(p1-p2));
            }
        }
        for(int i=1;i<=m;++i) {
            double xx=pow(p[i].x*p[i].y*p[i].y,1.0/3),yy=pow(p[i].x*p[i].x*p[i].y,1.0/3);
            Point p1(0,p[i].y+yy); Point p2(p[i].x+xx,0);
            if((i!=1||((p[i-1]-p1)^(p2-p1))+eps>=0)&&(i==m||((p[i+1]-p1)^(p2-p1))+eps>=0)) {
                ans=min(ans,length(p1-p2));
            }
        }
        printf("%.3lf",ans);
    }
    return 0;
}