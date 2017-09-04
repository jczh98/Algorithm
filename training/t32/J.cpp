#include <bits/stdc++.h>
using namespace std;
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
    bool operator < (const Point &c) const { return x<c.x || (x==c.x && y<c.y); }
    Point operator - (const Point &c) const { return Point(x-c.x,y-c.y); }
    int operator ^ (const Point &c) const { return x*c.y-y*c.x; }
    int operator * (const Point &c) const { return x*c.x + y*c.y;}
    int operator | (const Point &c) const { return (x-c.x)*(x-c.x)+(y-c.y)*(y-c.y); }
}point[1000005];
int Length(Point a) {
    return (a * a);
}
int n, p1, p2, p3 = 0, mx = INT_MAX;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &point[i].x, &point[i].y);
    }
    p1 = 1;
    for(int i = 2; i <= n; i++) {
        if((point[i] | point[p1]) < mx) {
            mx = (point[i] | point[p1]);
            p2 = i;
        }
    }
    //cout << p2 << endl;
    double cs = 1.0;
    for(int i = 2; i <= n; i++) {
        if(i == p2) continue;
        if((point[p1].x-point[p2].x) * (point[p1].y-point[i].y) - (point[p1].x - point[i].x)*(point[p1].y-point[p2].y) == 0) continue;
        int a2 = Length(point[i] - point[p1]), b2 = Length(point[i] - point[p2]), c2 = Length(point[p1] - point[p2]);
        //cout << a2 << " " << b2 << " " << c2 << endl;
        if((a2 + b2 - c2) * 1.0 / 2.0 / sqrt(1.0 * a2 * b2) < cs) {
            cs = (a2 + b2 - c2) * 1.0 / 2.0 / sqrt(1.0 * a2 * b2);
            p3 = i;
        }
    }
    if(!p3) {
        printf("No\n");
    }else {
        printf("Yes\n%d %d %d\n", p1, p2, p3);
    }
    return 0;
}

