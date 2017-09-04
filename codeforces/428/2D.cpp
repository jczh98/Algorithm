#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL n, x, a[1000010], power[1000010], cnt, p[1000010], ans = 0, mx = 1000000;
int main() {
    cin >> n;
    power[0] = 1;
    for(int i = 1; i <= mx; i++) power[i] = (power[i - 1] * 2) % MOD;
    for(LL i = 1; i <= n; i++) {
        cin >> x;
        a[x]++;
    }
    for(LL i = 2; i <= mx; i++) p[i] = i;
    for(LL i = 2; i <= mx; i++) {
        for(int j = i * 2; j <= mx; j += i) {
            p[j] -= p[i];
        }
    }
    for(LL i = 2; i <= mx; i++) {
        cnt = 0;
        for(LL j = i; j <= mx; j += i) {
            cnt += a[j];
        }
        if(cnt == 0) continue;
        ans = (ans + (p[i] % MOD * cnt % MOD * power[cnt - 1] % MOD) % MOD + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}

