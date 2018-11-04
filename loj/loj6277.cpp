#include <bits/stdc++.h>
using namespace std;
int n, a[500005], opt, q, l, r, x, blocks, bl[500005], add[500005];
int main() {
    scanf("%d", &n);
    blocks = (int)sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]); bl[i] = (i - 1) / blocks + 1;
    }
    while(n--){
        scanf("%d", &opt);
        if(opt == 0) {
            scanf("%d%d%d", &l, &r, &x);
            if(bl[l] == bl[r]) {
                for(int i = l; i <= r; ++i) {
                    a[i] += x;
                }
            }else {
                for(int i = l; i <= bl[l] * blocks; ++i) a[i] += x;
                for(int i = (bl[r] - 1) * blocks + 1; i <= r; ++i) a[i] += x;
                for(int i = bl[l] + 1; i < bl[r]; ++i) add[i] += x;
            }
        }else {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", a[r] + add[bl[r]]);
        }
    }
    return 0;
}
