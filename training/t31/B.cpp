#include <bits/stdc++.h>
using namespace std;
int n, x[10000], y[10000], kase = 1;
int main() {
    while(scanf("%d", &n) != EOF) {
        if(n == 0) break;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        int min_sum_x = INT_MAX, min_sum_y = INT_MAX, min_x = INT_MAX, min_y = INT_MAX;
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int j = 1; j <= n; j++) {
                sum += abs(x[i] - x[j]);
            }
            if(min_sum_x >= sum) {
                min_sum_x = sum;
                if(min_x >= x[i]) {
                    min_x = x[i];
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            int sum = 0;
            for(int j = 1; j <= n; j++) {
                sum += abs(y[i] - y[j]);
            }
            if(min_sum_y >= sum) {
                min_sum_y = sum;
                if(min_y >= y[i]) {
                    min_y = y[i];
                }
            }
        }
        printf("Case %d: (%d,%d) %d\n", kase++, min_x, min_y, min_sum_x + min_sum_y);
    }
}

