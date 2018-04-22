#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
int n, v[N], t[N];
LL sum[N], ans[N];
int C[N];
inline void add(int x, int c) {
    while(x < N) {C[x] += c; x += x & (-x);}
}
inline int query(int x) {
    int ret = 0;
    while(x > 0) {ret += C[x]; x -= x & (-x);}
    return ret;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &t[i]), sum[i] = sum[i - 1] + 1LL * t[i];
    for(int i = 1; i <= n; ++i) {
        LL x = 1LL * v[i] + sum[i - 1];
        int p = lower_bound(sum + 1, sum + 1 + n, x) - sum;
        add(i, 1);
        if(x != sum[p]) {
            ans[p] += x - sum[p - 1]; add(p, -1);
        }else add(p + 1, -1);
        ans[i] += 1LL * query(i) * t[i];
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i];
        if(i == n) cout << endl;
        else cout << " ";
    }
    return 0;
}