#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll T[505][100005], inv[100005], B[202][202];
int t, a, b;
ll quick_mod(ll a, ll b) {
    ll ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
            b--;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int target;
int main() {
    inv[1] = 1;
    for (int i = 2; i <= 100000; i++) {
        inv[i] = (ll)(mod - mod / i) * 1LL * inv[mod % i] % mod;
    }
    T[0][0] = 1;
    for(int i = 1; i <= 501; ++i) {
        T[i][0] = 1, T[i][(i - 1)* 200] = quick_mod(2, (i - 1) * 200); 
    }
    for(int i = 1; i <= 200; ++i) {
        B[i][0] = 1, B[i][i] = quick_mod(2, i);
    }
    for(int i = 1; i <= 200; ++i) {
        for(int j = 1; j < i; ++j) {
            B[i][j] = (B[i - 1][j - 1] + B[i - 1][j]) % mod;
        }
    }
    for(int i = 1; i <= 501; ++i) {
        ll pre = (i - 1) * 200, nn = pre;
        if(i == 1) pre = 1, nn = 1;
        T[i][1] = pre + 1;
        for(int j = 2; j < nn; ++j) {
            pre = (pre * (nn - j + 1) % mod * inv[j] % mod) % mod;
            T[i][j] = (T[i][j - 1] + pre) % mod;
        } 
        //for(int j = nn + 1; j <= 100000; ++j) T[i][j] = T[i][nn];
    }
    scanf("%d", &t); 
    while(t--) {
        scanf("%d%d", &a, &b);
        if(a < 200) {
            printf("%lld\n", B[a][b]);
        }else {
            target = a / 200 + 1;
            ll ans = 0, pre = 1, pos = 0;
            int h = a - (target - 1) * 200, mul, lev = (target - 1) * 200;
            for(int i = b; i >= max(b - h, 0); --i) {
                if(T[target][i] == 0) mul = T[target][lev]; else mul = T[target][i];
                ans = (ans + pre * 1LL * mul % mod) % mod;   
                pos++;
                pre = (pre * (h - pos + 1) % mod * inv[pos] % mod) % mod; 
            }
            printf("%lld\n", ans);            
        }
    }
    return 0;
}