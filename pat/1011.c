#include <stdio.h>

float w[3], t[3], l[3];

int main() {
    for (int i = 0; i < 3; ++i) {
        scanf("%f%f%f", &w[i], &t[i], &l[i]);
    }
    float ans = 1;
    for (int i = 0; i < 3; ++i) {
        if (w[i] > t[i]) {
            if (w[i] > l[i]) {
                printf("W ");
                ans *= w[i];
            } else {
                printf("L ");
                ans *= l[i];
            }
        } else {
            if (t[i] > l[i]) {
                printf("T ");
                ans *= t[i];
            } else {
                printf("L ");
                ans *= l[i];
            }
        }
    }
    ans = (ans * 0.65 - 1 ) * 2;
    printf("%.2f\n", ans);
    return 0;
}
