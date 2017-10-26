#include <bits/stdc++.h>
using namespace std;
int a, b, f, k;
int main() {
    scanf("%d%d%d%d", &a, &b, &f, &k);
    int rem = b;
    int ans = 0;
    if ((a - f) > b || f > b) {
        printf("-1\n");
    }else if (k == 1) {
        if (b >= a) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    } else if (k == 2) {
        if (2 * (a - f) > b || f > b) {
            printf("-1\n");
        }else {
            for (int i = 1; i <= k; i++) {
                if (i == k) {
                    if (rem < a) {
                        ans++;
                    }
                } else {
                    if (i & 1) {
                        if (rem < 2 * a - f) {
                            ans++, rem = b + f - a;
                        } else {
                            rem -= a;
                        }
                    } else {
                        if (rem < a + f) {
                            ans++, rem = b - f;
                        } else {
                            rem -= a;
                        }
                    }
                }
            }
            printf("%d\n", ans);
        }

    } else {
        if (2 * (a - f) > b || 2 * f > b) {
            printf("-1\n");
        }else {
            for (int i = 1; i <= k; i++) {
                if (i == k) {
                    if (rem < a) {
                        ans++;
                    }
                } else {
                    if (i & 1) {
                        if (rem < 2 * a - f) {
                            ans++, rem = b + f - a;
                        } else {
                            rem -= a;
                        }
                    } else {
                        if (rem < a + f) {
                            ans++, rem = b - f;
                        } else {
                            rem -= a;
                        }
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
