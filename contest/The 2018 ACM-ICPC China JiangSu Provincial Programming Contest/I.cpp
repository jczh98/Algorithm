#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll f[200][200], pos[200], ans;
int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        ans = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &f[i][j]);
            }
        }
        for(int i = 1; i <= m; ++i) {
            ll tmp = 0;
            for(int j = 1; j <= m; ++j) {
                if(tmp < f[i][j]) {
                    tmp = f[i][j]; pos[i] = j;
                }
            }
        }
        for(int i = 1; i <= m; ++i) {
            ll cur = i, ret = 0;
            int cnt = 1;
            while(1) {
                if(pos[cur] == i) break;
                ret += f[cur][pos[cur]];
                cur = pos[cur];
                cnt++;
                if(cnt == n) break;
            }
            if(cnt == n) {
                ans = max(ans, ret);
                continue;
            }
            int cycle = cnt;
            //cout << cycle << endl;
            int k = n / cycle, rem = n % cycle;
            cout << k << " " << rem << endl;
            cnt = 1;
            ll ret2 = f[cur][i];
            cur = i;
            while(--rem > 0) {
                ret2 += f[cur][pos[cur]];
                cur = pos[cur];
            }
            ans = max(ans, k*ret+ret2);
        }
        cout << ans << endl;
    }
}