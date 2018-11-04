#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
int t, len, K;
ll dp[11][11][11][55], cnt[11], x[100], ten[100], ans;
char s[100];
inline void add(ll &x, ll y) {x=(x+y)%mod;}
ll dfs(ll a, ll b, ll c, ll k) {
    if(k == 0) return b==10?a*c:0;
    if(~dp[a][b][c][k]) return dp[a][b][c][k];
    dp[a][b][c][k] = 0;
    add(dp[a][b][c][k], dfs(b, a, c, k-1));
    add(dp[a][b][c][k], dfs(c, b, a, k-1));
    add(dp[a][b][c][k], dfs(a, c, b, k-1));
    add(dp[a][b][c][k], 1LL*(len-3)*(len-4)/2*dfs(a, b, c, k-1));
    ll tmp[11];
    memcpy(tmp, cnt, sizeof(tmp));
    tmp[a]--;tmp[b]--;tmp[c]--;
    for(int i = 0; i <= 10; ++i) {
        if(tmp[i]>=0)add(dp[a][b][c][k], 1LL*tmp[i]*dfs(i, b, c, k-1));
        if(tmp[i]>=0)add(dp[a][b][c][k], 1LL*tmp[i]*dfs(a, i, c, k-1));
        if(tmp[i]>=0)add(dp[a][b][c][k], 1LL*tmp[i]*dfs(a, b, i, k-1));
    }
    return dp[a][b][c][k];
}
int main() {
    ten[0] = 1;
    for(int i = 1; i < 100; ++i) ten[i] = ten[i-1]*10%mod;
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(dp, -1, sizeof(dp));
        scanf("%d", &K);
        scanf("%s", s);
        len = strlen(s);
        for(int i = 0; i < len; ++i) {
            if(s[i] == '*') x[i] = 10; else x[i] = s[i] - '0';
            cnt[x[i]]++;
        }
        for(int i = 0; i < len; ++i) {
            for(int j = i + 1; j < len; ++j) {
                for(int l = j + 1; l < len; ++l) {
                    ans=(ans+ten[j-i-1]*ten[len-l-1]%mod*dfs(x[i], x[j], x[l], K)%mod)%mod;
                }
            }
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}