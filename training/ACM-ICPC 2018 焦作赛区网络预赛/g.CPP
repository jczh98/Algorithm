#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7, MOD2=1e9+6;
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) {
            ret = (ret * a) % mod;
        }
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
int t;
string n;
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int len = n.size();
        ll ret = 0;
        for(int i = 0; i < len; ++i) {
            ret = (ret*10 + n[i] - '0') % MOD2;
        }
        //cout << ret << endl;
        ret = (ret - 1 + MOD2) % MOD2;
        if(len > 9) cout << qpow(2, ret + MOD2, MOD) << endl;
        else cout << qpow(2, ret, MOD) << endl;  
    }
    return 0;
}