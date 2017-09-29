#include <bits/stdc++.h>
using namespace std;
int t, k, ans_up, ans_down;
void Solve(int up1, int down1, int up2, int down2, long double decimal) {
    if(up1 == up2 && down1 == down2) return;
    if (fabs((long double)1.0 * up1 / down1 - decimal) < fabs((long double)1.0 * ans_up / ans_down - decimal)) ans_up = up1, ans_down = down1;
    if (fabs((long double)1.0 * up2 / down2 - decimal) < fabs((long double)1.0 * ans_up / ans_down - decimal)) ans_up = up2, ans_down = down2;
    int up = (up1 + up2), down = (down1 + down2);
    if(down > 100000) return;
    if((long double)(up * 1.0 / down) >= decimal) Solve(up1, down1, up, down, decimal);
    else Solve(up, down, up2, down2, decimal);
}
int flag = 0;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &k);
        flag = 0;
        for (int i = 1; i <= 50; i++) {
            if (i * i * i == k) {
                printf("%d/1\n", i * i);
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        ans_up = 0; ans_down = 1;
        long double val = pow((long double)k, (long double)2.0 / 3);
        int integer = floor(val);
        long double decimal = val - integer * 1.0;
        Solve(0, 1, 1, 1, decimal);
        printf("%d/%d\n", ans_up + integer * ans_down, ans_down);
    }
    return 0;
}