#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[50005], len, bl[50005], opt, l, r, c;
LL sum[50005], add_tag[50005];
void rebuild(int x) {
    sum[x] = 0;
    for(int i = (x - 1) * len + 1; i <= x * len; ++i) sum[x] += a[i];
}
int main() {
    scanf("%d", &n); len = (int) sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); bl[i] = (i - 1) / len + 1; sum[bl[i]] += a[i];
    }
    for(int kase = 1; kase <= n; ++kase) {
        scanf("%d%d%d%d", &opt, &l, &r, &c);
        if(opt == 0) {
            for(int i = l; i <= min(r, bl[l] * len); ++i) a[i] += c; rebuild(bl[l]);
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * len + 1; i <= r; ++i) a[i] += c; rebuild(bl[r]);
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) add_tag[i] += c;
        }else {
            LL ans = 0;
            for(int i = l; i <= min(r, bl[l] * len); ++i) ans = (ans + a[i] + add_tag[bl[i]]) % (c + 1);
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * len + 1; i <= r; ++i) ans = (ans + a[i] + add_tag[bl[i]]) % (c + 1);
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) ans = (ans + sum[i] + add_tag[i] * len) % (c + 1);
            cout << ans << endl;
        }
    }
    return 0;
}