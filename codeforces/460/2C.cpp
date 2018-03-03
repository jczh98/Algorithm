#include <bits/stdc++.h>
using namespace std;
char G[3000][3000];
int n, m, k, ans = 0, ans_special = 0;
int cal(string s) {
    int cnt = 0, ret = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '.') {
            cnt++;
        }else if(s[i] == '*') {
            if(cnt >= k) {
                ret += cnt - k + 1;
            }
            cnt = 0;
        }
    }
    if(cnt >= k) {
        ret += cnt - k + 1;
    }
    return ret;
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", G[i] + 1);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(G[i][j] == '.') ans_special++;
        }
    }
    if(k == 1) {
        printf("%d\n", ans_special);
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        string tmp = "";
        for(int j = 1; j <= m; ++j) tmp += G[i][j];
        ans+=cal(tmp);
    }
    for(int i = 1; i <= m; ++i) {
        string tmp = "";
        for(int j = 1; j <= n; ++j) tmp += G[j][i];
        ans+=cal(tmp);
    }
    cout << ans << endl;
    return 0;
}