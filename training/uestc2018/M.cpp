#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL qpow(LL a, LL b) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a);
        a = a * a; b >>= 1;
    }
    return ret;
}
LL a[200005], b[100];
bool insert(LL val) {
    for (LL i = 63; i >= 0; i--)
        if (val & (1LL << i)) {
            if (!b[i]) {
                b[i] = val;
                break;
            }
            val ^= a[i];
        }
    return val > 0;
}
int t, n, r;
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int sz = unique(a + 1, a + 1 + n) - (a + 1);
        r = 0;
        for(int i = 1; i <= sz; ++i) {
            if(insert(a[i])) ++r;
        }
        cout << r << endl;
        cout << qpow(2, r) - sz << endl;
    }
    return 0;
}