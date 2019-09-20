#include <stdio.h>

int n, a, b = 0, ans = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (a > b) {
            ans += (a - b) * 6;
        }
        if (a < b) {
            ans += (b - a) * 4;
        }
        ans += 5;
        b = a;
    }
    printf("%d\n", ans);
    return 0;
}
