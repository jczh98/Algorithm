#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
struct node {
    int x, y;
    bool operator < (const node & rhs) const {
        return x == rhs.x ? y > rhs.y : x > rhs.x;
    }
}e[N], f[N];
int n, m, c[101];
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(c, 0, sizeof(c));
        int num = 0;
        LL ans = 0;
        for (int i = 0; i < n; i++) scanf("%d%d", &e[i].x, &e[i].y);
        for (int i = 0; i < m; i++) scanf("%d%d", &f[i].x, &f[i].y);
        sort(e, e + n);
        sort(f, f + m);
        for (int i = 0, j = 0; i < m; i++) {
            while (j < n && e[j].x >= f[i].x) {
                c[e[j].y]++; j++;
            }
            for (int k = f[i].y; k <= 100; k++) {
                if (c[k]) {
                    num++; c[k]--;
                    ans = ans + 500 * f[i].x + 2 * f[i].y;
                    break;
                }
            }
        }
        cout << num << " " << ans << endl;
    }
    return 0;
}
