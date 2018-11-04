#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pre[100005], suf[100005], base = 233, mod = 19260817, BASE[100005];
int n;
char s[100005];
ll pre_hash(int l, int r) {
    return (pre[r] - BASE[r-l+1] * pre[l-1]%mod+mod)%mod;
}
ll suf_hash(int l, int r) {
    int rr = n-l+1, ll = n-r+1;
    //cout << ll << " " << rr << endl;
    return (suf[rr] - BASE[rr-ll+1] * suf[ll-1]%mod+mod)%mod;
}
bool check(int l, int r) {
    if(r-l+1==1) return true;
    int mid = (l+r)>>1;
    if((r-l+1)&1) {
        //cout << pre_hash(l,mid-1) << " "  << suf_hash(mid+1,r) << endl;
        if(pre_hash(l,mid-1)==suf_hash(mid+1,r)) return true;
    }else {
        if(pre_hash(l, mid)==suf_hash(mid+1,r)) return true;
    }
    return false;
}
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for(int i = 1; i <= n / 2; ++i) {
        if(s[i] != s[n-i+1]) {
            cout << 1 << endl;
            return 0;
        }
    }
    BASE[0]=1;
    for(int i = 1; i <= n; ++i) BASE[i] = BASE[i-1]*base % mod;
    for(int i = 1; i <= n; ++i) pre[i] = (pre[i-1]*base + s[i] - 'a') % mod;
    for(int i = 1; i <= n/2; ++i) swap(s[i],s[n-i+1]);
    //printf("%s\n", s+1);
    for(int i = 1; i <= n; ++i) suf[i] = (suf[i-1]*base + s[i] - 'a') % mod;
    for(int i = 1; i <= n/2; ++i) swap(s[i],s[n-i+1]);
    //cout << check(3,5) << endl;
    for(int i = 1; i <= n; ++i) {
        if(!check(1, i) && !check(i+1,n)) {
            //cout << i << endl;
            cout << 2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}