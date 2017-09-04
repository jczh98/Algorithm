#include <bits/stdc++.h>

#define N 100005
using namespace std;

inline long long Max(long long x, long long y) { return x > y ? x : y; }

struct point {
    long long x, y;

    point(long long x = 0, long long y = 0) : x(x), y(y) {}

    bool operator<(const point &c) const { return x < c.x || (x == c.x && y < c.y); }

    point operator-(const point &c) const { return point(x - c.x, y - c.y); }

    long long operator*(const point &c) const { return x * c.y - y * c.x; }

    long long operator|(const point &c) const { return (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y); }
} u[N * 4], p[N * 4];

int n, tot_points;

int convex_hull(point a[], point p[], int tot) {
    sort(a + 1, a + 1 + tot);
    int top = 0;
    for (int i = 1; i <= tot; i++) {
        while (top > 1 && (p[top] - p[top - 1]) * (a[i] - p[top - 1]) <= 0) top--;
        p[++top] = a[i];
    }
    int k = top;
    for (int i = tot - 1; i >= 1; i--) {
        while (top > k && (p[top] - p[top - 1]) * (a[i] - p[top - 1]) <= 0) top--;
        p[++top] = a[i];
    }
    return top - 1;
}

long long rotating_calipers(point p[], int top) {
    long long ans = 0;
    p[top + 1] = p[1];
    int now = 2;
    for (int i = 1; i <= top; i++) {
        while ((p[i + 1] - p[i]) * (p[now] - p[i]) < (p[i + 1] - p[i]) * (p[now + 1] - p[i])) {
            now++;
            if (now == top + 1) now = 1;
        }
        ans = Max(ans, (p[now] | p[i]));
    }
    return ans;
}
long long x, y, w;
int t;
int main() {
    scanf("%d", &t);
    while(t--) {
        tot_points = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld%lld", &x, &y, &w);
            u[tot_points].x = x; u[tot_points].y = y; tot_points++;
            u[tot_points].x = x + w; u[tot_points].y = y; tot_points++;
            u[tot_points].x = x; u[tot_points].y = y + w; tot_points++;
            u[tot_points].x = x + w; u[tot_points].y = y + w; tot_points++;
        }
        int top = convex_hull(u, p, tot_points - 1);
        printf("%lld\n", rotating_calipers(p, top));
    }
    return 0;
}