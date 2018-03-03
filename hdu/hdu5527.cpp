#include <bits/stdc++.h>
using namespace std;
int t, p, c[11], sum[11], ans;
int idx[11] = {0, 1, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};
void dfs(int rem, int k, int cnt) {
    if(rem < 0) return;
    if(k == 0) {
        if(rem == 0) ans = max(ans, cnt);
        return;
    }
    int cur = max(rem - sum[k - 1], 0);
    int num = cur / idx[k] + (cur % idx[k] == 0 ? 0 : 1);
    if(num <= c[k]) dfs(rem - num * idx[k], k - 1, cnt + num);
    num++;
    if(num <= c[k]) dfs(rem - num * idx[k], k - 1, cnt + num);
}
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = -1;
        memset(sum, 0, sizeof(sum));
        scanf("%d", &p);
        for(int i = 1; i <= 10; ++i) scanf("%d", &c[i]);
        for(int i = 1; i <= 10; ++i) sum[i] = sum[i - 1] + c[i] * idx[i];
        dfs(p, 10, 0);  
        printf("%d\n", ans);
    }
    return 0;
}