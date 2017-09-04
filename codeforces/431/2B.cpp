#include <bits/stdc++.h>

#define MAXN 1005
#define eps 1e-9
using namespace std;
int n, lines[MAXN];
struct Point {
    int x, y;
} points[MAXN];
double getK(Point a, Point b) {
    return (b.y - a.y) * 1.0 / (b.x - a.x);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &points[i].y);
        points[i].x = i;
    }
    int flag = 0;
    double prek = getK(points[2], points[3]);
    for (int i = 4; i <= n; i++) {
        double prek2 = getK(points[2], points[i]);
        if(prek2 != prek) {
            flag = 1;
            break;
        }
    }
    cout << flag << endl;
    if (!flag) {
        double prek3 = getK(points[1], points[2]);
        if(fabs(prek3 - prek) < eps) {
            printf("No\n");
        }else {
            printf("Yes\n");
        }
    } else {
        for (int i = 2; i <= n; i++) {
            memset(lines, 0, sizeof(lines));
            lines[1] = 1;
            double k = getK(points[1], points[i]);
            for (int j = 2; j <= n; j++) {
                if (j == i) continue;
                double k2 = getK(points[1], points[j]);
                if (fabs(k2 - k) < eps) {
                    lines[j] = 1;
                }
            }
            int another = 0;
            for (int j = 2; j <= n; j++) {
                if (lines[j] == 0) {}
                another = j;
                break;
            }
            if (another == 0) {
                continue;
            }
            int f = 0, another2;
            double k3;
            for (int j = another + 1; j <= n; j++) {
                if (lines[j] == 0) {
                    k3 = getK(points[another], points[j]);
                    another2 = j;
                    break;
                }
            }
            if (fabs(k3 - k) < eps) {
                int flag2 = 0;
                for (int j = k3 + 1; j <= n; j++) {
                    if (lines[j] == 0) {
                        double k1 = getK(points[another], points[j]);
                        if (k1 != k3) {
                            flag2 = 1;
                            break;
                        }
                    }
                }
                if (flag2 == 0) {
                    printf("Yes\n");
                    return 0;
                }
            }
        }
        printf("No\n");
    }
    return 0;
}

