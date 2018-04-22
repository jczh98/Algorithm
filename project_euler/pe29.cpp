#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
set<pll> mp;
LL quick_pow(LL a, LL b, LL m) {
    LL ret = 1;
    for(; b; b >>= 1) {
        if(b & 1) ret = (ret * a) % m;
        a = (a * a) % m;
    }
    return ret;
}
int main() {
    for(LL i = 2; i <= 100; ++i) {
        for(LL j = 2; j <= 100; ++j) {
            mp.insert(make_pair(quick_pow(i, j, 1000000000+7), quick_pow(i, j, 100000000+9)));
        }
    }
    cout << mp.size() << endl;
}