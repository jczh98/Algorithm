#include <stdio.h>

int k1, n1[20], n2[20], k2;
float a1[20], a2[20], ans[3000];
int main() {
    scanf("%d", &k1);
    for (int i = 1; i <= k1; ++i) scanf("%d%f", &n1[i], &a1[i]);
    scanf("%d", &k2);
    for (int i = 1; i <= k2; ++i) scanf("%d%f", &n2[i], &a2[i]);
    for (int i = 1; i <= k2; ++i) {
        for (int j = 1; j <= k1; ++j) {
            ans[n1[j]+n2[i]] += a1[j] * a2[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 2000; ++i) {
        if (ans[i] != 0.0) {
            cnt++;
        }
    }
    printf("%d ", cnt);
    for (int i = 2000; i >= 0; --i) {
        if (ans[i] != 0.0) {
            printf("%d %.1f", i, ans[i]);
            cnt--;
            if (cnt != 0) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
