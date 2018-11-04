#include <bits/stdc++.h>
#define ff(i, x, y) for(int i = x;i <= y;i++)
#define fs(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
typedef long long ll;
ll t;
const double eps = 1e-8;
double x0, y0, x1, y1, x2, y2, r, vx, vy;
double k1, k2, b1, b2, tpx1, tpy1, tpx2, tpy2;
double dis(double a, double b, double c, double d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}
int pan(double a, double b) {
    if(a * b > 0)
        return 1;
    return 0;
}
void slove_x(double a, double b, double c) {
    tpx1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
    tpx2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    return;
}
double cross(double a, double b, double c, double d) {
    return a * d - b * c;
}
int main() {
    scanf("%lld", &t);
    int cnt = 0;
    while(t--) {
        cnt++;
        printf("Case #%d: ",cnt);
        cin >> x0 >> y0;
        cin >> r;
        cin >> x1 >> y1 >> vx >> vy >> x2 >> y2;
        double d;
        if(vx == 0) {
            d = fabs(x1 - x2);
        }
        else if(vy == 0) {
            d = fabs(y1 - y2);
        }
        else {
            k1 = vy / vx;
            b1 = y1 - k1 * x1;
            k2 = -1 / k1;
            b2 = y0 - k2 * x0;
            double x3, y3;
            x3 = -(b1 - b2) / (k1 - k2);
            y3 = k2 * x3 + b2;
            d = dis(x0, y0, x3, y3);
        }
        if(d < r - eps) {
            slove_x(1 + k1 * k1, 2 * (b1 - y0 - x0) , x0 * x0 +(b1 - y0) * (b1 - y0) - r * r);
            tpy1 = k1 * tpx1 + b1;
            tpy2 = k1 * tpx2 + b1;
            double d1 = dis(tpx1, tpy1, x1, y1), d2 = dis(tpx2, tpy2, x1, y1);
            if(d1 > d2) {
                tpx1 = tpx2;
                tpy1 = tpy2;
                swap(d1, d2);
            }
            double dd = dis(x1, y1, x2, y2);
            if(fabs(y2 - k1 * x2 - b1) < eps && dd < d1) {
                printf("Yes\n");
                continue;
            }
            double k3, b3, delta1 = atan(k1), delat2;
            k3 = (y0 - tpy1) / (x0 - tpx1);
            delta2 = atan(k3);
            k3 = delta1 + delat2 * 2;
            k3 = tan(k3);
            b3 = tpy1 - k3 * tpx1;
            if(fabs(y2 - k3 * x2 - b3) < eps && !pan(cross(x0 - tpx1, y0 - tpy1, x1 - tpx1, y1 - tpy1), cross(x0 - tpx1, y0 - tpy1, x2 - tpx1, y2 - tpy1))) {
                printf("Yes\n");
            }
            else
                printf("No\n");
        }
        else {
            if(fabs(y2 - k1 * x2 - b1) < eps && pan(y2 - y1, vy) && pan(x2 - x1, vx)) {
                printf("Yes\n");
            }
            else
                printf("No\n");
        }
    }
    return 0;
}
