#include <bits/stdc++.h>
using namespace std;
int n, m, G[2005][2005], sum[2005];
char str[2005][2005];
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", str[i] + 1);
        for(int j = 1; j <= m; ++j) {
            sum[j] += (str[i][j] - '0');
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int tmp = 1;
        for(int j = 1; j <= m; ++j) {
            if(str[i][j] == '1') {
                if(sum[j] < 2) {
                    tmp = 0; break;
                }
            }
        }
        if(tmp) {
            ans = 1;break;
        }
    }
    if(ans) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}