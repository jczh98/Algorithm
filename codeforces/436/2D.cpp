#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> que;
int n, cnt[200005], vis[200005], fans[200005], ans = 0, now = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> now; cnt[now]++; fans[i] = now;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 0) {
            que.push(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[fans[i]] > 1) {
            int cur = que.top();
            if (cur < fans[i]) {
                ans++;
                cnt[fans[i]]--;
                fans[i] = cur;
                que.pop();
            } else if (cur > fans[i]) {
                if (vis[fans[i]]) {
                    ans++;
                    cnt[fans[i]]--;
                    fans[i] = cur;
                    que.pop();
                } else {
                    vis[fans[i]] = 1;
                }
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        printf("%d%c", fans[i], i == n ? '\n' : ' ');
    }
    return 0;
}