#include <bits/stdc++.h>
using namespace std;
map<int, int> mem;
int t, n;
inline int query(int x) {
    if(mem.find(x) != mem.end()) return mem[x];
    printf("1 %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return mem[x] = ret;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        mem.clear();
        scanf("%d", &n);
        int l = 1, r = n, k;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(query(mid) <= query(1)) {
                l = mid;
            }else r = mid - 1;
        }
        k = l;
        if(query(n) != query(n - k + 1)) {
            printf("2 %d\n", query(n));
            fflush(stdout);
            continue;
        }
        if(query(n) == query(n - k)) {
            printf("2 %d\n", query(1));
            fflush(stdout);
            continue;
        }
        l = 1; r = n / k - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(query(mid * k + 1) != query((mid + 1) * k)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        printf("2 %d\n", query(l * k + 1));
        fflush(stdout);
    }
    return 0;
}