#include <stdio.h>
#include <string.h>

int n, d;
int num[1000], len, sum;
int check(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    while(scanf("%d", &n) != EOF) {
        if (n < 0) break;
        scanf("%d", &d);
        memset(num, 0, sizeof(num));
        len = 0; sum = 0;
        int ori = n;
        while(n) {
            num[len++] = n%d;
            n/=d;
        }
        for (int i = 0; i < len; ++i) {
            sum = sum * d + num[i];
        }
        if (check(sum) && check(ori)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
