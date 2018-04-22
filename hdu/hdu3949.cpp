#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX_BASE = 60;
int t, n, q, kase = 1; 
LL a[10005], b[MAX_BASE + 5];
vector<LL> base;
inline void gauss() {
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= n; ++i) {
        for(LL j = MAX_BASE; j >= 0; --j) {
            if((a[i] >> j) & 1) {
                if(b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i]; 
                    for(LL k = j - 1; k >= 0; --k) if (b[k] && ((b[j] >> k) & 1)) b[j] ^= b[k];
                    for(LL k = j + 1; k <= MAX_BASE; ++k) if ((b[k] >> j) & 1) b[k] ^= b[j];
                    break;
                }
            }
        }
    }
    base.clear();
    for(int i = 0; i <= MAX_BASE; ++i) if(b[i]) base.push_back(b[i]);
}
inline LL query(LL k) {
    if(base.size() < n) --k;
    if(k >= (1LL << base.size())) return -1;
    LL ret = 0;
    for(int i = 0; i < base.size(); ++i) {
        if((k >> i) & 1) ret ^= base[i];
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        gauss();
        scanf("%d", &q);
        int k;
        cout << "Case #" << kase++ << ":" << endl;
        while(q--) {
            scanf("%lld", &k);
            cout << query(k) << endl;
        }        
    }
    return 0;
}