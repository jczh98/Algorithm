#include <bits/stdc++.h>
using namespace std;
double p, f[2][1005];
int n, mx = 60000, mx_turn = 700;
int main() {
    cin >> p >> n;
    if(n == 0) {
        printf("1\n");
    }else {
        for(int i = 1; i <= mx; i++) {
            int cur = i & 1;
            memset(f[cur], 0, sizeof(f[cur]));
            f[cur][0] = 1;
            for(int j = 1; j <= mx_turn; j++) {
                f[cur][j] += f[cur ^ 1][j + 2] * p + f[cur ^ 1][j - 1] * (1.0 - p);
            }
        }
        printf("%.9f\n", f[mx & 1][n]);
    }
    return 0;
}