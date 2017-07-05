

#include <bits/stdc++.h>
#define eps 1e-7
using namespace std;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    bool operator < (const Point &rhs) const {return x<rhs.x||(x==rhs.x&&y<rhs.y);}
    Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y);}
    Point operator + (const Point &rhs) const {return Point(x+rhs.x,y+rhs.y);}
    Point operator * (const double p) { return Point(x*p,y*p) ;}
    Point operator / (const double p) {return Point(x/p,y/p);}
    bool operator == (const Point &rhs) const {return dcmp(x-rhs.x)==0&&dcmp(y-rhs.y)==0;}
};
typedef Point Vector;
double Cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double Dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double Length(Point a,Point b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
double Length(Vector a) {return sqrt(Dot(a,a));}
bool Onsegment(Point p,Point a,Point b)
{
    return dcmp(Cross(b-a,p-a)) == 0 && dcmp(Dot(b-p,a-p)) < 0 || (p == a) || (p == b);
}
bool OnLine(Point p,Point a,Point b)
{
    return fabs(Cross(p-a,a-b))/Length(b-a);
}
bool SegmentIntersection(Point a,Point b,Point c,Point d)
{
    double d1 = Cross(b-a,c-a),d2 = Cross(b-a,d-a),d3 = Cross(d-c,a-c),d4 = Cross(d-c,b-c);
    if(dcmp(d1)*dcmp(d2) < 0 || dcmp(d3)*dcmp(d4) < 0) return true;
    else if(dcmp(d1) == 0 && !OnLine(c,a,b) ) return true;
    else if(dcmp(d2) == 0 && !OnLine(d,a,b) ) return true;
    else if(dcmp(d3) == 0 && !OnLine(a,c,d) ) return true;
    else if(dcmp(d4) == 0 && !OnLine(b,c,d) ) return true;
    else return false;
}
bool Segmentsection(Point a,Point b,Point c,Point d)
{
    double d1 = Cross(b-a,c-a),d2 = Cross(b-a,d-a),d3 = Cross(d-c,a-c),d4 = Cross(d-c,b-c);
    if(dcmp(d1)*dcmp(d2) < 0 && dcmp(d3)*dcmp(d4) < 0) return true;
    else if(dcmp(d1) == 0 && Onsegment(c,a,b) ) return true;
    else if(dcmp(d2) == 0 && Onsegment(d,a,b) ) return true;
    else if(dcmp(d3) == 0 && Onsegment(a,c,d) ) return true;
    else if(dcmp(d4) == 0 && Onsegment(b,c,d) ) return true;
    else return false;
}
bool pointInpoly(Point p,Point a,Point b,Point c,Point d)
{
    double d1 = Cross(b-a,p-a);
    double d2 = Cross(d-c,p-c);
    double d3 = Cross(c-b,p-b);
    double d4 = Cross(a-d,p-d);
    return dcmp(d1)*dcmp(d2) > 0 && dcmp(d3)*dcmp(d4) > 0;
}
Point Segment(Point p,Vector v,Point q,Vector w)
{
    Vector u = p-q;
    double t = Cross(w,u) / Cross(v,w);
    return p + v*t;
}
struct Line
{
    Point s,e;
    Line(Point s = 0,Point e = 0) :s(s),e(e){}
};
Point Max(Point a,Point b)
{
    return a.y > b.y ? a : b;
}
Point a,b,c,d;
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y)!=EOF)
    {
        Point P1=Max(a,b),P2=Max(c,d);
        if(!Segmentsection(a,b,c,d)) printf("0.00\n");
        else if(a.y == b.y || c.y == d.y) printf("0.00\n");
        else if(!Cross(b-a,c-d)) printf("0.00\n");
        else
        {
            Point k=Segment(a,b-a,c,d-c),P3=Point(P1.x,P1.y+1),P4=Point(P2.x,P2.y+1);
            if(SegmentIntersection(P1,P3,c,d))
            {
                Point k1=Segment(P1,P3-P1,c,d-c);
                if(Onsegment(k1,P2,k))
                {
                    if(dcmp(P1.y-k1.y)<=0)
                    {
                        printf("0.00\n");continue;
                    }
                }
            }
            if(SegmentIntersection(P2,P4,a,b))
            {
                Point k1=Segment(P2,P4-P2,a,b-a);
                if(Onsegment(k1,P1,k))
                {
                    if(dcmp(P2.y-k1.y)<=0)
                    {
                         printf("0.00\n");continue;
                    }
                }
            }
            P3=Point(P1.x+1,P1.y);
            P4=Point(P2.x+1,P2.y);
            if(SegmentIntersection(P1,P3,c,d))
            {
                Point k1=Segment(P1,P3-P1,c,d-c);
                if(Onsegment(k1,P2,k))printf("%.2lf\n",fabs(Cross(P1-k,k1-k))/2);continue;
            }
            if(SegmentIntersection(P2,P4,a,b))
            {
                Point k1 = Segment(P2,P4-P2,a,b-a);
                if(Onsegment(k1,P1,k))printf("%.2lf\n",fabs(Cross(P2-k,k1-k))/2);continue;
            }
        }
    }
    return 0;
}
