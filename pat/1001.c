#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    int sum = a + b;
    if (sum < 0) {
        int abssum = abs(sum);
        if (abssum > 999) {
            if (abssum > 999999) {
                printf("-%d,%03d,%03d\n", abssum / 1000000, abssum % 1000000 / 1000, abssum % 1000);
            } else {
                printf("-%d,%03d\n", abssum / 1000, abssum % 1000);
            }
        } else {
            printf("-%d\n", abssum);
        }
    } else {
        if (sum > 999) {
            if (sum > 999999) {
                printf("%d,%03d,%03d\n", sum / 1000000, sum % 1000000 / 1000, sum % 1000);
            } else {
                printf("%d,%03d\n", sum / 1000, sum % 1000);
            }
        } else {
            printf("%d\n", sum);
        }
    }
    return 0;
}
