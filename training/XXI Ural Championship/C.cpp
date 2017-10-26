#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 100;
const LL M = 1000005;
LL n, min_w, max_w, wt[N], c[N];
bitset<M> f;
bool Judge(LL mid) {
    f.reset();f[0] = 1;
    for(int i = 1; i <= n; ++i) {
        LL num = c[i] / mid;
        for(int k = 1; num; k <<= 1) {
            LL mul = min(k * 1LL, num);
            f |= f << mul * wt[i];
            num -= mul;
        }
    }
    for(int i = min_w; i <= max_w; ++i) if(f[i]) return true;
    return false;
}
int main() {
    cin >> n >> min_w >> max_w;
    for(int i = 1; i <= n; ++i) cin >> wt[i] >> c[i];
    LL L = 0, R = 1000005, mid;
    while(L < R) {
        mid = (L + R + 1) / 2;
        if(Judge(mid)) L = mid;else R = mid - 1;
    }
    cout << L << endl;
    return 0;
}