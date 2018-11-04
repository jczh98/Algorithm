#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, q, bl[500005], len, opt, l, r;
LL a[500005], add[500005], x;
vector<LL> pre[500005];
inline void rebuild(int x) {
    pre[x].clear();
    for(int i = (x - 1) * len + 1; i <= x * len; ++i) pre[x].push_back(a[i]);
    sort(pre[x].begin(), pre[x].end());
}
int main() {
    scanf("%d%d", &n, &q); len = (int) sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]); bl[i] = (i - 1) / len + 1; pre[bl[i]].push_back(a[i]);
    }
    int num = n / len + (n % len ? 1 : 0);
    for(int i = 1; i <= num; ++i) sort(pre[i].begin(), pre[i].end());
    while(q--) {
        scanf("%d", &opt);
        if(opt == 1) {
            scanf("%d%d%lld", &l, &r, &x);
            for(int i = l; i <= min(r, bl[l] * len); ++i) a[i] += x; rebuild(bl[l]);
            if(bl[l] != bl[r]) {
                for(int i = (bl[r] - 1) * len + 1; i <= r; ++i) a[i] += x; rebuild(bl[r]);
            }
            for(int i = bl[l] + 1; i < bl[r]; ++i) add[i] += x;
        }else {
            scanf("%lld", &x); int Min = INT_MAX, Max = -INT_MAX;
            for(int i = 1; i <= num; ++i) {
                if(binary_search(pre[i].begin(), pre[i].end(), x - add[i])) {
                    for(int j = (i - 1) * len + 1; j <= i * len; ++j) {
                        if(a[j] + add[i] == x) {
                            Min = j; break;
                        }
                    }
                    break;
                }
            }
            for(int i = num; i >= 1; --i) {
                if(binary_search(pre[i].begin(), pre[i].end(), x - add[i])) {
                    for(int j = i * len; j >= (i - 1) * len + 1; --j) {
                        if(a[j] + add[i] == x) {
                            Max = j; break;
                        }
                    }
                    break;
                }
            }
            if(Min == INT_MAX || Max == -INT_MAX) printf("-1\n");
            else printf("%d\n", Max - Min);
        }
    }
    return 0;
}