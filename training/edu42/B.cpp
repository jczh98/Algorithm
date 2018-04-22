#include <bits/stdc++.h>
using namespace std;
int n, a, b, seat, ans, tmp;
char s[200005];
int main() {
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '.') {
            seat++;
        } else {
            if (seat > 0) {
                if (seat % 2 == 0) {
                    tmp = min(seat / 2, a);
                    ans += tmp;
                    a -= tmp;
                    tmp = min(seat / 2, b);
                    ans += tmp;
                    b -= tmp;
                } else {
                    if (a > b) {
                        tmp = min(seat / 2 + 1, a);
                        ans += tmp;
                        a -= tmp;
                        tmp = min(seat / 2, b);
                        ans += tmp;
                        b -= tmp;
                    } else {
                        tmp = min(seat / 2, a);
                        ans += tmp;
                        a -= tmp;
                        tmp = min(seat / 2 + 1, b);
                        ans += tmp;
                        b -= tmp;
                    }
                }
            }
            seat = 0;
        }
    }
    if (seat > 0) {
        if (seat % 2 == 0) {
            tmp = min(seat / 2, a);
            ans += tmp;
            a -= tmp;
            tmp = min(seat / 2, b);
            ans += tmp;
            b -= tmp;
        } else {
            if (a > b) {
                tmp = min(seat / 2 + 1, a);
                ans += tmp;
                a -= tmp;
                tmp = min(seat / 2, b);
                ans += tmp;
                b -= tmp;
            } else {
                tmp = min(seat / 2, a);
                ans += tmp;
                a -= tmp;
                tmp = min(seat / 2 + 1, b);
                ans += tmp;
                b -= tmp;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
