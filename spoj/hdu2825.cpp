#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 20090717;
struct ACM {
#define N 110
    int nxt[N][26], fail[N], end[N];
    int root, sz;
    int newnode() {
        for (int i = 0; i < 26; i++) nxt[sz][i] = -1;
        end[sz++] = 0;
        return sz - 1;
    }
    void init() {
        sz = 0;
        root = newnode();
    }
    void insert(char *buf, int id) {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++) {
            if (nxt[now][buf[i] - 'a'] == -1)
                nxt[now][buf[i] - 'a'] = newnode();
            now = nxt[now][buf[i] - 'a'];
        }
        end[now] |= (1 << id);
    }
    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 26; i++) {
            if (nxt[root][i] == -1)
                nxt[root][i] = root;
            else {
                fail[nxt[root][i]] = root;
                Q.push(nxt[root][i]);
            }
        }
        while (!Q.empty()) {
            int now = Q.front();
            Q.pop();
            end[now] |= end[fail[now]];
            for (int i = 0; i < 26; i++) {
                if (nxt[now][i] == -1)
                    nxt[now][i] = nxt[fail[now]][i];
                else {
                    fail[nxt[now][i]] = nxt[fail[now]][i];
                    Q.push(nxt[now][i]);
                }
            }
        }
    }

} ac;
int n, m, k;
char str[110];
ll dp[30][200][(1<<10)+5];
int main() {
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        if(n == 0 && m == 0 && k == 0) break;
        ac.init();
        for(int i = 1; i <= m; ++i) {
            scanf("%s", str);
            ac.insert(str, i - 1);
        }
        ac.build();
        for(register int i = 0; i <= n; ++i) {
            for(register int j = 0; j < ac.sz; ++j) {
                for(register int S = 0; S < (1<<m); ++S) {
                    dp[i][j][S] = 0;
                }
            }
        }
        dp[0][0][0] = 1;
        for(register int i = 0; i < n; ++i) {
            for(register int j = 0; j < ac.sz; ++j) {
                for(register int S = 0; S < (1<<m); ++S) {
                    if(!dp[i][j][S]) continue;
                    for(register int c = 0; c < 26; ++c) {
                        int nj = ac.nxt[j][c], nS = S|ac.end[nj];
                        dp[i+1][nj][nS] = (dp[i+1][nj][nS] + dp[i][j][S]) % MOD;
                    }
                }
            }
        }
        ll ans = 0;
        for(register int S = 0; S < (1<<m); ++S) {
            int cnt = 0;
            for(register int j = 0; j < m; ++j) if(S&(1<<j)) cnt++;
            if(cnt >= k) {
                for(register int j = 0; j < ac.sz; ++j) {
                    ans = (ans + dp[n][j][S]) % MOD;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}