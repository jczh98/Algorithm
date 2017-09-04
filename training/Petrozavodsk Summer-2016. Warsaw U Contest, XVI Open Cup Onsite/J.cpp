#include <bits/stdc++.h>
#define eps 1e-9
#define MAXN 200005
#define pi acos(-1.0);
using namespace std;
typedef long long LL;
struct Point {
    LL x, y;
    double angle;
    int type;
    Point(LL x = 0, LL y = 0) : x(x), y(y) {}

    bool operator<(const Point &rhs) const { return x < rhs.x || (x == rhs.x && y < rhs.y); }

    Point operator-(const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }

    LL operator^(const Point &rhs) const { return x * rhs.y - y * rhs.x; }

    LL operator*(const Point &rhs) const { return x * rhs.x + y * rhs.y;}

    void GetAngle() {
        angle = acos((double) x / sqrt((double) (x * x + y * y)));
        if (y < 0) angle = 2.0 * pi - angle;
    }

}point[MAXN], seg[2 * MAXN + 10], origin[MAXN], vertical[MAXN], tmp;

LL Length(Point a) { return a * a;}

LL n, a, b, cnt, ans = 0;

bool cmp(const Point &a, const Point &b) {
    if (a.angle < b.angle - eps) return true;
    if (a.angle > b.angle + eps) return false;
    if ((a ^ b) > 0) return true;
    if ((a ^ b) < 0) return false;
    return (Length(a) < Length(b));
}

int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) cin >> point[i].x >> point[i].y;
    for(int i = 1; i <= n; i++) {
        cnt = 1;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            seg[cnt] = point[j] - point[i];
            seg[cnt].type = 0;
            cnt++;
            seg[cnt] = Point(-seg[cnt - 1].y, seg[cnt - 1].x);
            seg[cnt].type = 1;
            cnt++;
        }
        cnt--;
        for(int i = 1; i <= cnt; i++) seg[i].GetAngle();
        sort(seg + 1, seg + cnt + 1, cmp);
        int r;
        for(int l = 1; l <= cnt; l++) {
            r = l;
            while(r <= cnt && (seg[r] ^ seg[l]) == 0 && (seg[r] * seg[l]) > 0) r++;
            r--;
            int ori = 1, ver = 1;
            for(int k = l; k <= r; k++) {
                if(seg[k].type == 0) origin[ori++] = seg[k];
                else vertical[ver++] = seg[k];
            }
            ver--; ori--;
            int L = 1, R = 1;
            for(int k = ori; k >= 1; k--) {
                while(L <= ver && (origin[k] * vertical[L]) < a * 2) L++;
                while(R <= ver && (origin[k] * vertical[R]) <= b * 2) R++;
                ans += (R - L);
            }
            l = r;
        }
    }
    cout << ans << endl;
    return 0;
}