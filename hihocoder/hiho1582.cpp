#include <bits/stdc++.h>
#define MN 1010
#define pi acos(-1.0)
using namespace std;
struct Point {
    int x, y, pos;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(Point &rhs) const {
        return (x == rhs.x && y == rhs.y);
    }
    bool operator<(const Point &rhs) const { return x < rhs.x || (x == rhs.x && y < rhs.y); }
    Point operator-(const Point &rhs) const { return Point(x - rhs.x, y - rhs.y); }
    int operator^(const Point &rhs) const { return x * rhs.y - y * rhs.x; }
} a[MN], p[MN];
int n, number[MN];
int ConvexHull() {
    sort(a + 1, a + 1 + n);
    int top = 0;
    for (int i = 1; i <= n; ++i) {
        while (top > 1 && ((p[top - 1] - p[top - 2]) ^ (a[i] - p[top - 2])) < 0) top--;
        p[top++] = a[i]; number[top - 1] = a[i].pos;
    }
    int k = top;
    for (int i = n - 1; i >= 1; --i) {
        while (top > k && ((p[top - 1] - p[top - 2]) ^ (a[i] - p[top - 2])) < 0) top--;
        p[top++] = a[i]; number[top - 1] = a[i].pos;
    }
    if(n > 1) --top;
    return top;
}
bool Judge(Point a, Point b, Point c) {
    return ((a - b) ^ (a - c)) == 0;
}
int t, vis[MN];
char ans[MN];
int main() {
    scanf("%d", &t);
    for(; t; t--) {
        memset(vis, 0, sizeof(vis));
        memset(ans, '\0', sizeof(ans));
        memset(number, 0, sizeof(number));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);a[i].pos = i;
        }
        if(n == 2 || n == 1) {
            printf("NO\n");
            continue;
        }
        if(n == 3) {
            if(Judge(a[1], a[2], a[3])) {
                printf("YES\n");
                sort(a + 1, a + 1 + n);
                for(int i = 1; i <= n; ++i) {
                    if(i & 1) ans[a[i].pos] = 'A'; else ans[a[i].pos] = 'B';
                }
                for(int i = 1; i <= n; ++i) {
                    printf("%c", ans[i]);
                }
                printf("\n");
            }else {
                printf("NO\n");
            }
            continue;
        }
        printf("YES\n");
        int flag = 0;
        for(int i = 3; i <= n; i++) {
            if(!Judge(a[1], a[2], a[i])) {
                flag = 1;break;
            }
        }
        if(!flag) {
            sort(a + 1, a + 1 + n);
            for(int i = 1; i <= n; ++i) {
                if(i & 1) ans[a[i].pos] = 'A'; else ans[a[i].pos] = 'B';
            }
            for(int i = 1; i <= n; ++i) {
                printf("%c", ans[i]);
            }
            printf("\n");
            continue;
        }
        int m = ConvexHull();
        //cout << m << endl;
        if(m == n) {
            for(int i = 0; i < m; ++i) {
                //cout << number[i] << endl;
                if(i & 1) ans[number[i]] = 'A'; else ans[number[i]] = 'B';
            }
        }else {
            for(int i = 0; i < m; ++i) {
                //cout << number[i] << endl;
                ans[number[i]] = 'A';
                vis[number[i]] = 1;
            }
            for(int i = 1; i <= n; ++i) {
                if(!vis[i]) ans[i] = 'B';
            }
        }
        for(int i = 1; i <= n; ++i) {
            printf("%c", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

