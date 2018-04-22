#include <bits/stdc++.h>
using namespace std;
typedef  long long ull;
typedef pair<long long, long long> pll;
int h, w, q;
long long mod=1e9+7, mod2=1e9+9;
char s[1005][1005];
ull Hash[1005][1005], seed1 = 573279901, seed2 =573279947, pw1[1005], pw2[1005],pw[1010][1010],pre[1010][1010];
inline ull getHash(int l1, int r1, int l2, int r2) {
    int l = l2 - l1 + 1, r = r2 - r1 + 1;
    ull h = Hash[l2][r2];
    h = (h-Hash[l2 - l][r2]+mod )%mod;
    h = (h-Hash[l2][r2 - r] +mod)%mod;
    h = (h+Hash[l2 - l][r2 - r])%mod;
    return h;
}
inline ull getpre(int l1, int r1, int l2, int r2) {
    int l = l2 - l1 + 1, r = r2 - r1 + 1;
    ull h = pre[l2][r2];
    h = (h- pre[l2 - l][r2]+mod )%mod;
    h = (h- pre[l2][r2 - r] +mod)%mod;
    h = (h+ pre[l2 - l][r2 - r])%mod;
    return h;
}
set<ull>hu;
int main() {
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; ++i) scanf("%s", s[i] + 1);
    ull a=1,b=1;
    pw[0][0]=1;
    for(int i = 1; i <= h; ++i) {
            a=(a*seed1)%mod;
            b=1;
        for(int j = 1; j <= w; ++j) {
            b=(b*seed2)%mod;
            pw[i][j]=(a*b)%mod;
            if(s[i][j]=='1')
            {
                Hash[i][j] = pw[i][j];
                pre[i][j]=1;
            }
            pw[0][j]=b;
            hu.insert(pw[i][j]);
        }
        pw[i][0]=a;
    }
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            Hash[i][j] = (Hash[i][j]+Hash[i][j-1])%mod;
            pre[i][j]=(pre[i][j]+pre[i][j-1]);
        }
    }
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            Hash[i][j] = (Hash[i][j]+Hash[i-1][j])%mod;
            pre[i][j]=(pre[i][j]+pre[i-1][j]);
        }
    }
    scanf("%d", &q);
    while(q--) {
        int l1, l2, l3, l4, r1, r2, r3, r4;
        scanf("%d%d%d%d%d%d%d%d", &l1, &r1, &l2, &r2, &l3, &r3, &l4, &r4);
        ull h1 = getHash(l1 + 1, r1 + 1, l2 + 1, r2 + 1), h2 = getHash(l3 + 1, r3 + 1, l4 + 1, r4 + 1);
        if(l1>l3)h2=(h2*pw[l1-l3][0])%mod;
        else
            h1=(h1*pw[l3-l1][0])%mod;
        if(r1>r3)h2=(h2*pw[0][r1-r3])%mod;
        else
            h1=(h1*pw[0][r3-r1])%mod;
        ull val;
        int n1 = getpre(l1 + 1, r1 + 1, l2 + 1, r2 + 1), n2 = getpre(l3 + 1, r3 + 1, l4 + 1, r4 + 1);
        if(n1>n2)
            val=(h1-h2+mod)%mod;
        else
            val=(h2-h1+mod)%mod;
        if(h1 == h2) {
            printf("Perfect\n");
        }else if(hu.count(val) && abs(n1 - n2) == 1) {
            printf("One difference\n");
        }else printf("Wrong\n");
    }
    return 0;
}

