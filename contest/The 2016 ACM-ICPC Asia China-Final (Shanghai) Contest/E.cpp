#include <bits/stdc++.h>
using namespace std;
long double x[10000], sum;
double a, b;
int t, n, ans;
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        sum = 0.0;
        ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lf:%lf", &a, &b);
            x[i] = 1.0*round(a*1000)/(round(a*1000)+round(b*1000));
        }
        sort(x+1, x+1+n);
        for(int i = 1; i <= n; ++i) {
            sum += x[i];
            if(sum < 1.0) {
                ans++;
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}