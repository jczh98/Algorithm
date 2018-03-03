#include <bits/stdc++.h>
using namespace std;
int t, n, k, x[1000], cover[1000];
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(cover, 0, sizeof(cover));
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= k; ++i) scanf("%d", &x[i]);
        for(int times = 1; times <= 200; ++times) {
            for(int i = 1; i <= k; ++i) {
                for(int j = x[i] - (times - 1); j <= x[i] + (times - 1); ++j) {
                    if(j >= 1 && j <= n) cover[j] = 1;
                }
            }
            int flag = 0;
            for(int i = 1; i <= n; ++i) {
                if(!cover[i]) flag = 1;
            }
            if(!flag)  {
                printf("%d\n", times); break;
            }
        }
    }
    return 0;
}