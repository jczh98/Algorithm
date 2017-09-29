#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL sum[1000005], pre[1000005];
bool Judge(LL x) {
    if(x % 7 == 0) return true;
    while(x) {
        if(x % 10 == 7) return true;
        x /= 10;
    }
    return false;
}
int t, n;
int main() {
    for(LL i = 1; i <= 1000000; ++i) sum[i] = sum[i - 1] + i * i;
    for(LL i = 1; i <= 1000000; ++i) {
        pre[i] += pre[i - 1];
        if(Judge(i)) pre[i] += i * i;
    }
    scanf("%d", &t);
    for(;t; t--) {
        scanf("%d", &n);
        printf("%lld\n", sum[n] - pre[n]);
    }
    return 0;
}

