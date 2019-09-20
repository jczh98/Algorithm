#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
int N1[2000], k;
int N2[2000], k2, ks = 0;
float a1[2000], a2[2000], tmp;
int main() {
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d%f", &N1[i], &tmp);
        ks = max(N1[i], ks);
        a1[N1[i]] = tmp;
    }
    scanf("%d", &k2);
    for (int i = 1; i <= k2; ++i) {
        scanf("%d%f", &N2[i], &tmp);
        ks = max(N2[i], ks);
        a2[N2[i]] = tmp;
    }
    for (int i = ks; i >= 0; --i) {
        a1[i] += a2[i];
    }
    int kk = 0;
    for (int i = ks; i >= 0; --i) {
        if (a1[i] != 0.0) {
            kk++;
        }
    }
    printf("%d", kk);
    if (kk != 0) {
        printf(" ");
    }
    for (int i = ks; i >= 0; --i) {
        if (a1[i] != 0.0) {
            printf("%d %.1f", i, a1[i]);
            kk--;
            if (kk != 0) {
                printf(" ");
            }
        }
    }
    return 0;
}
