#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
#define ULL unsigned long long
typedef long long ll;
const int maxn = 2000000 + 20;
const ll mod = 1e9 + 7;
typedef pair<ll,ll> par;
const ll P = 1313131, PP = 19260817;
ll sqr[maxn], has[maxn];
ll sqr2[maxn], has2[maxn];
unordered_map<ll, int> mmp;
__gnu_pbds::gp_hash_table<ll,bool> h;
// int Laxt[maxn], Next[maxn], cnt = 0;

const ll MOD = 1e9+7, MOD2 = 1e9+9;

char c[maxn];


typedef long long ll;
ll pre[maxn];
ll qpow(ll a, ll n) {
	ll ans = 1;
	while(n) {
		if(n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
void init() {
	int i;
	int len = strlen(c + 1);
	for(i = 1; i <= len; i++) {
		pre[i] = (pre[i-1] * 10LL + (c[i] - '0')) % mod;
	}
}
ll findd(int l, int r) {
	return (pre[r] - pre[l - 1] * qpow(10LL, r - l + 1) % mod + mod) % mod;
}




// bool _insert(par Now) {
//     //int u = Now % MOD;
//     par u = make_pair(Now.first% MOD, Now.second % MOD2);
//     for (int i = Laxt[u]; i; i = Next[i]) {
//         if (V[i] == Now) return true;
//     }
//     Next[++cnt] = Laxt[u];
//     Laxt[u] = cnt;
//     V[cnt] = Now;
//     return false;
// }
ll ans = 0;
void _hash(int x, int y) {
    ll Now1 = (has[y] - has[x - 1] * sqr[y - x + 1] % MOD + MOD) % MOD;
    ll Now2 = (has2[y] - has2[x - 1] * sqr2[y - x + 1] % MOD2 + MOD2) % MOD2;
    //par Now = make_pair(Now1, Now2);
    ll Now = Now1 * 1000000000 + Now2;
    // if(mmp.find(Now) == mmp.end()) {
    //     ans = (ans + findd(x, y)) % mod;
    //     mmp[Now] = 1;
    // }
    if(!h[Now]) {
        ans = (ans + findd(x, y)) % mod;
        h[Now] = true;
    }
    // if (!_insert(Now)) {
    //     ans = (ans + findd(x, y)) % mod;
    //     //++ans;
    // }
}

int r[maxn];
void _malacher() {
    int R = 0, Mid = 0, Len;
    scanf("%s", c + 1);
    Len = strlen(c + 1);
    init();
    sqr[0] = 1; sqr2[0] = 1;
    for (int i = 1; i <= Len; i++) {
        sqr[i] = sqr[i - 1] * P % MOD;
        has[i] = (has[i - 1] * P % MOD + c[i]) % MOD;
        sqr2[i] = sqr2[i - 1] * PP % MOD2;
        has2[i] = (has2[i - 1] * PP % MOD2 + c[i]) % MOD2;
    }
    for (int i = 1; i <= Len; ++i) {
        _hash(i, i);
        if (R > i) r[i] = min(r[2 * Mid - i], R - i);
        while (i + r[i] + 1 <= Len && c[i + r[i] + 1] == c[i - r[i] - 1]) {
            _hash(i - r[i] - 1, i + r[i] + 1);
            r[i]++;
        }
        if (i + r[i] > R) {
            R = i + r[i];
            Mid = i;
        }
    }

    //cnt = 0;
    Mid = 0;
    R = 0;
    //memset(Laxt, 0, sizeof(Laxt));
    memset(r, 0, sizeof(r));
    for (int i = 2; i <= Len; ++i) {
        if (R > i) r[i] = min(r[2 * Mid - i], R - i + 1);
        while (i + r[i] <= Len && c[i + r[i]] == c[i - r[i] - 1]) {
            _hash(i - r[i] - 1, i + r[i]);
            ++r[i];
        }
        if (i + r[i] - 1 > R) {
            R = i + r[i] - 1;
            Mid = i;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    _malacher();
    return 0;
}