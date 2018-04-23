#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull base = 233, pw[2000005], hs[2000005], hs2[2000005];
char S[2000005], T[2000005];
unordered_map<ull, int> Hash;
int len, n, ans, len2;
inline ull calc(int l, int r) {
    return hs[r] - pw[r - l + 1] * hs[l - 1];
}
inline ull calc2(int l, int r) {
    return hs2[r] - pw[r - l + 1] * hs2[l - 1];
}
int main() {
    scanf("%s", T + 1); len = strlen(T + 1);
    for(register int i = 1; i <= len; ++i) T[i + len] = T[i];
    pw[0] = 1;
    for(register int i = 1; i <= len * 2; ++i) {
        pw[i] = pw[i - 1] * base;
        hs[i] = hs[i - 1] * base + T[i] - 'a';
    }
    for(register int i = 1; i <= len; ++i) Hash[calc(i, i + len - 1)] = 1;
    scanf("%d", &n);
    while(n--) {
        ans = 0;
        scanf("%s", S + 1); len2 = strlen(S + 1);
        hs2[0] = 0;
        for(register int i = 1; i <= len2; ++i) {
            hs2[i] = hs2[i - 1] * base + S[i] - 'a';
        }
        for(register int i = 1; i + len - 1<= len2; ++i) {
            if(Hash.count(calc2(i, i + len - 1))) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}