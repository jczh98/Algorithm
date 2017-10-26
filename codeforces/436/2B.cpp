#include <bits/stdc++.h>
using namespace std;
int n, cnt[30], ans = 0;
char str[1000];
int main() {
    scanf("%d", &n);
    scanf("%s", str + 1);
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            int flag = 1;
            for(int k = i; k <= j; ++k) {
                if(isupper(str[k])) {flag = 0; break;}
            }
            if(flag) {
                memset(cnt, 0, sizeof(cnt));
                for(int k = i; k <= j; ++k) {
                    cnt[str[k] - 'a'] = 1;
                }
                int tmp = 0;
                for(int k = 0; k <= 26; ++k) {
                    if(cnt[k]) tmp++;
                }
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

