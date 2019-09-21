#include <cstdio>

int sz, n, m, H[20000];

bool check(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    scanf("%d%d%d", &sz, &n, &m);
    while(!check(sz)) sz++;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        int flag = 0;
        for (int j = 0; j < sz; ++j) {
            int id = (x + j*j)%sz;
            if (H[id] == 0) {
                H[id] = x;
                flag = 1;
                break;
            }
        }
        if (!flag) printf("%d cannot be inserted.\n", x);
    }
    double sum = 0.0;
    for (int i = 1; i <= m; ++i) {
        int cnt = 1;
        int x;
        scanf("%d", &x);
        for (int j = 0; j < sz; ++j) {
            int id = (x + j*j) % sz;
            if (H[id] == x || H[id] == 0) {
                break; 
            }
            cnt++;
        }
        sum += cnt;
    }
    printf("%.1lf\n", sum/(1.0*m));
    return 0;
}
