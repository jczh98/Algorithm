#include <bits/stdc++.h>
#define MN 10010
#define pi acos(-1.0)
using namespace std;
typedef long long LL;

struct Point {
    LL x, y;

    Point(LL x = 0, LL y = 0) : x(x), y(y) {}

    bool operator<(const Point &rhs) const { return x < rhs.x || (x == rhs.x && y < rhs.y); }

    Point operator-(const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }

    LL operator^(const Point &rhs) const { return x * rhs.y - y * rhs.x; }
} a[MN], p[MN];

int n, tot;

void ConvexHull() {
    sort(a + 1, a + 1 + n);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        while (tot > 1 && ((p[tot - 1] - p[tot - 2]) ^ (a[i] - p[tot - 2])) <= 0)tot--;
        p[tot++] = a[i];
    }
    int k = tot;
    for (int i = n - 1; i > 0; i--) {
        while (tot > k && ((p[tot - 1] - p[tot - 2]) ^ (a[i] - p[tot - 2])) <= 0)tot--;
        p[tot++] = a[i];
    }
    if (n > 1)tot--;
}

bool Judge(Point A) {
    int l = 1, r = tot - 2, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        LL a1 = (p[mid] - p[0]) ^ (A - p[0]);
        LL a2 = (p[mid + 1] - p[0]) ^ (A - p[0]);
        if (a1 >= 0 && a2 <= 0) {
            if (((p[mid + 1] - p[mid]) ^ (A - p[mid])) >= 0)return true;
            return false;
        } else if (a1 < 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int s, ans = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;;
    ConvexHull();
    cin >> s;
    Point t;
    for (int i = 1; i <= s; i++) {
        cin >> t.x >> t.y;
        if (Judge(t)) ans++;
    }
    printf("%d", ans);
    return 0;
}