#include <bits/stdc++.h>
using namespace std;
double r[4], dp[100];
int n;
int main() {
    scanf("%d%lf%lf%lf%lf", &n, &r[0], &r[1], &r[2], &r[3]);
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(j < 3) {
                if(i - j - 1 >= 0) dp[i] = dp[i - (j + 1)] + pow(1 + dp[i - (j + 1)], j + 1);
            }else {
                if(i - j - 2 >= 0) dp[i] = dp[i - (j + 2)] + pow(1 + dp[i - (j + 2)], j + 2);
            }
        }
    }
    return 0;
}