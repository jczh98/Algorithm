#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;
typedef long long LL;
LL ans;
const LL MOD = 1e9 + 7;
int nxt[MAXN], extend[MAXN], t;
char ss1[MAXN], ss2[MAXN];
string s1, s2;
void GetNext(string S) {
    nxt[0] = S.size();
    int j = 0, k = 1, p, L;
    while(j + 1 < S.size() && S[j] == S[j + 1]) j++;
    nxt[1] = j;
    for(int i = 2; i < S.size(); i++) {
        p = nxt[k] + k - 1;
        L = nxt[i - k];
        if(i + L < p + 1) nxt[i] = L;
        else {
            j = max(0, p - i + 1);
            while(i + j < S.size() && S[i + j] == S[j]) j++;
            nxt[i] = j;
            k = i;
        }
    }
}
void ExtendKmp(string P, string T) {
    GetNext(P);
    int j = 0, k = 1, p, L;
    while(j < P.size() && j < T.size() && P[j] == T[j]) j++;
    extend[0] = j;
    for(int i = 1; i < T.size(); i++) {
        p = extend[k] + k - 1;
        L = nxt[i - k];
        if(i + L < p + 1) extend[i] = L;
        else {
            j = max(0, p - i + 1);
            while(i + j < T.size() &&  j < P.size() && T[i + j] == P[j]) j++;
            extend[i] = j;
            k = i;
        }
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        memset(nxt, 0, sizeof(nxt));
        memset(extend, 0, sizeof(extend));
        scanf("%s%s", ss1, ss2);
        s1 = ss1; s2 = ss2;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        ExtendKmp(s2, s1);
        for(int i = 0; i < s1.size(); i++) {
            if(extend[i]) {
                ans = (ans + ((LL) extend[i] * (extend[i] + 1) / 2) % MOD) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
}

