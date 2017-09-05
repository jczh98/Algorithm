#include <bits/stdc++.h>
using namespace std;
int n, k, t;
int main() {
    scanf("%d%d%d", &n, &k, &t);
    if(t >= k && t <= n ) {
        printf("%d\n", k);
    }else {
        if(t < k) {
            printf("%d\n", t);
        }
        if(t > n) {
            printf("%d\n", k + n - t);
        }
    }
    return 0;
}