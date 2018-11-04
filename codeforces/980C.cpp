#include <bits/stdc++.h>
using namespace std;
int n, k, p[100005], ans[1000];
int main() {
    memset(ans, -1, sizeof(ans));
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for(int i = 1; i <= n; ++i) {
        if(ans[p[i]] == -1) {
            for(int j = max(0, p[i] - k + 1); j <= p[i]; ++j) {
                if(ans[j] == -1 || ans[j] == j) {
                    for(int l = j; l <= p[i]; ++l) {
                        ans[l] = j;
                    }
                    break;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[p[i]] << " ";
    }
    return 0;
}
