#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define ll long long
char n1[20], n2[20], t[20];
int tag, radix;

ll cal(char *s, int rad) {
    int len = strlen(s);
    ll sum = 0;
    for (int i = 0; i < len; ++i) {
        if (isdigit(s[i])) {
            sum = sum * 1ll * rad + 1ll * (s[i] - '0');
        } else {
            sum = sum * 1ll * rad + 1ll * (s[i] - 'a' + 10);
        }
        if (sum < 0) {
            return -1;
        }
    }
    return sum;
}
int calmax(char *s) {
    int ret = 0;
    for (int i = 0; i < strlen(s); ++i) {
        if (isdigit(s[i])) {
            ret = max(ret, s[i] - '0');
        } else {
            ret = max(ret, s[i] - 'a' + 10);
        }
    }
    return ret+1;
}
int main() {
    scanf("%s%s", n1, n2);
    scanf("%d%d", &tag, &radix);
    if (tag == 2) {
        strcpy(t, n1);
        strcpy(n1, n2);
        strcpy(n2, t);
    }
    int len1 = strlen(n1), len2 = strlen(n2);
    int flag = 0;
    ll sum1 = cal(n1, radix);
    ll l = calmax(n2);
    ll r = sum1;
    while (l <= r) {
        ll mid = (l+r)>>1;
        ll tmp = cal(n2, mid);
        if (tmp >= sum1 || tmp == -1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (cal(n2, l) == sum1) {
        printf("%lld\n", l);
    } else {
        printf("Impossible\n");
    }
    return 0;
}
