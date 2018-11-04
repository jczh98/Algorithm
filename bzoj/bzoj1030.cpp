#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 10007;
struct ACM {
#define N 6010
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
            if (nxt[now][buf[i] - 'A'] == -1)
                nxt[now][buf[i] - 'A'] = newnode();
            now = nxt[now][buf[i] - 'A'];
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
int n, m;
char str[100];
ll dp[1200][6010];
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
int main() {
    scanf("%d%d", &n, &m);
    ac.init();
    for(int i = 1; i <= n; ++i) {
        scanf("%s", str);
        ac.insert(str,0);
    }
    ac.build();
    for(int i = 0; i <= m; ++i) {
        for(int j = 0; j < ac.sz; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < ac.sz; ++j) {
            if(!dp[i][j] || ac.end[j]) continue;
            for(int c = 0; c < 26; ++c) {
                int nj = ac.nxt[j][c];
                if(!ac.end[nj]) {
                    dp[i+1][nj] = (dp[i+1][nj] + dp[i][j]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < ac.sz; ++i) ans = (ans + dp[m][i]) % MOD;
    cout << (qpow(26, m, MOD) - ans + MOD) % MOD << endl;
    return 0;
}