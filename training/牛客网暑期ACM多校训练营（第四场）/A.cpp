#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[100005];
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
map<ll,ll> mp;
ll phi(ll k)
{
    ll i,s=k,x=k;
    if (mp.count(k)) return mp[x];					//记忆化存储
    for(i = 2;i * i <= k; i++)
    {
        if(k % i == 0) s = s / i * (i - 1);
        while(k % i == 0) k /= i;
    }
    if(k > 1) s = s / k * (k - 1);
    mp[x]=s; return s;
}
ll dfs(int x, ll mod) {
    if(x == 0 || mod == 1) return 0;
    if(s[x] == '2') {
        ll tmp = (qpow(2, (dfs(x - 1, phi(mod)) + phi(mod)) % phi(mod), mod) * 6LL % mod - 3LL + mod) % mod;
        //cout << mod << " " << tmp << endl << endl;;
        return tmp; 
    }
    if(s[x] == '0') {
        return (dfs(x - 1, mod) + 1LL + mod) % mod;
    }
    if(s[x] == '1') {
        return (2LL * dfs(x - 1, mod) % mod + 2LL + mod) % mod;
    }
    return 0;
}
int t;
int main() {
    //freopen("out.txt", "w", stdout);
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s + 1);
        printf("%lld\n", dfs(strlen(s + 1), 1e9+7));
    }
    return 0;
}