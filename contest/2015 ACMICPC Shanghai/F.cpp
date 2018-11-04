#include <bits/stdc++.h>
using namespace std;
int t, len, vis[30], ans;
char s[10000];
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        memset(vis, 0, sizeof(vis));
        ans = INT_MAX;
        scanf("%s", s); len = strlen(s);
        for(int i = 0; i < len; ++i) {
            if(!vis[s[i]-'a']) {
                vis[s[i]-'a'] = i;
            }else {
                ans = min(ans, i-vis[s[i]-'a']);
                vis[s[i]-'a'] = i;
            }
        }
        //printf("Case #%d: ", kase);
        //if(ans == INT_MAX) puts("-1");
        //else printf("%d\n", ans);
    }
    return 0;
}