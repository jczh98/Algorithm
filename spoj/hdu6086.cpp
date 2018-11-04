#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
struct ACM {
#define N 3000
    int nxt[N][2], fail[N], end[N], end2[N];
    int root, sz;
    int newnode() {
        for (int i = 0; i < 2; i++) nxt[sz][i] = -1;
        end2[sz] = 0; end[sz++] = 0;
        return sz - 1;
    }
    void init() {
        sz = 0;
        root = newnode();
    }
    void insert(string buf, int id) {
        int len = buf.size();
        int now = root;
        for (int i = 0; i < len; i++) {
            if (nxt[now][buf[i] - '0'] == -1)
                nxt[now][buf[i] - '0'] = newnode();
            now = nxt[now][buf[i] - '0'];
        }
        end[now] |= (1 << id);
    }
    void insert2(string buf, int id) {
        int len = buf.size();
        int now = root;
        for (int i = 0; i < len; i++) {
            if (nxt[now][buf[i] - '0'] == -1)
                nxt[now][buf[i] - '0'] = newnode();
            now = nxt[now][buf[i] - '0'];
        }
        end2[now] |= (1 << id);
    }   
    void build() {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 2; i++) {
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
            end2[now] |= end2[fail[now]];
            for (int i = 0; i < 2; i++) {
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
ll dp[2][3000][(1<<6)+5];
int t, n, L, len;
string str, rev;
int main() {
    scanf("%d", &t);
    while(t--) {
        ac.init();
        scanf("%d%d", &n, &L);
        for(int i = 0; i < n; ++i) {
            cin >> str;
            ac.insert(str, i);
            len = str.size();
            rev = str;
            reverse(rev.begin(), rev.end());
            for(int j = 0; j < len; ++j) rev[j] = (rev[j]-'0')^1+'0';
            ac.insert(rev, i);
            for(int j = 0; j < min(len, L); ++j) {
                int flag = 1;
                for(int k = j+1, l = j; k < len && l >= 0; ++k,--l) {
                    if(!(str[k]-'0')^(str[l]-'0')) {flag = 0; break;}
                }
                if(!flag) continue;
                string tmp = str.substr(0,j+1);
                for(int k = (j+1)*2; k < len; ++k) tmp = (char)((str[k]-'0')^1+'0') + tmp;
                //cout << tmp << endl;
                ac.insert2(tmp, i);
            }
        }
        ac.build();
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < ac.sz; ++j) {
                for(int S = 0; S < (1<<n); ++S) {
                    dp[i][j][S] = 0;
                }
            }
        }
        //cout << ac.sz << endl;
        int cur = 0;
        dp[cur][0][0] = 1;
        for(int i = 0; i < L; ++i) {
            memset(dp[cur^1], 0, sizeof(dp[cur^1]));
            for(int j = 0; j < ac.sz; ++j) {
                for(int S = 0; S < (1<<n); ++S) {
                    if(!dp[cur][j][S]) continue;
                    for(int c = 0; c < 2; ++c) {
                        int nj = ac.nxt[j][c];
                        if(i < L - 1) {
                            int nS = S|ac.end[nj];
                            dp[cur^1][nj][nS] = (dp[cur^1][nj][nS]+dp[cur][j][S])%MOD;
                        } else {
                            int nS = S|ac.end[nj]|ac.end2[nj];
                            dp[cur^1][nj][nS] = (dp[cur^1][nj][nS]+dp[cur][j][S])%MOD;
                        }
                    }
                }
            }
            cur ^= 1;
        }
        ll ans = 0;
        for(int i = 0; i < ac.sz; ++i) ans = (ans + dp[cur][i][(1<<n)-1])%MOD;
        cout << ans << endl;
    }
    return 0;
}