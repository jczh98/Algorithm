#include <bits/stdc++.h>
#define pi acos(-1.0)
#define eps -1e-9
using namespace std;
int n, flag;
struct Point{
    int a, b, c, d, e;
    Point(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0): a(a), b(b), c(c), d(d), e(e){};
    Point operator - (const Point & rhs) {
        return Point(a - rhs.a, b - rhs.b, c - rhs.c, d - rhs.d, e - rhs.e);
    }
}p[1005], ab, ac, bc;
int dot(Point aa, Point bb) {
    return aa.a * bb.a + aa.b * bb.b + aa.c * bb.c + aa.d * bb.d + aa.e * bb.e;
}
double xx, yy, ang;
vector<int> ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d%d%d", &p[i].a, &p[i].b, &p[i].c, &p[i].d, &p[i].e);
    }
    if(n > 11) {
        printf("0\n");
    }else {
        for(int i = 1; i <= n; i++) {
            flag = 0;
            for(int j = 1; j <= n; j++) {
                if(j == i) continue;
                for(int k = j + 1; k <= n; k++) {
                    ab = p[j] - p[i];
                    ac = p[k] - p[i];
                    bc = p[k] - p[j];
                    if(dot(ab, ab) + dot(ac, ac) > dot(bc, bc)) {
                        flag = 1;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag) {
                ans.push_back(i);
            }
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
