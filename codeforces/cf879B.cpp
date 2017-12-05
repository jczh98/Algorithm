#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, p[505], cur = 0, ans;
LL k;
int main() {
    scanf("%d%I64d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for(int i = 1; i <= n; ++i) {
        if(cur == k) {
            printf("%d\n", p[1]);
            return 0;
        }else {
            if(p[1] > p[2]) {
                int t = p[2];
                for(int j = 2; j < n; ++j) {
                    p[j] = p[j + 1];
                }
                p[n] = t;
                cur++;
            }else{
                swap(p[1], p[2]); cur = 0;
                int t = p[2];
                for(int j = 2; j < n; ++j) {
                    p[j] = p[j + 1];
                }
                p[n] = t;
                cur++;
            }
        }
    }
    printf("%d\n", p[1]);
    return 0;
}