#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, s[100005], cnt[10005], pre[100005];
LL dp[100005], col;
vector<int> sta[100005];
inline double slope(int x, int y) {
    return (double)((dp[x - 1] + col * (pre[x] - 1) * (pre[x] - 1)) - (dp[y - 1] + col * (pre[y] - 1) * (pre[y] - 1))) / (double)(col * (pre[x] - pre[y]));
}
int main() {
    scanf("%d", &n);
    int l = 1, r = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]); pre[i] = ++cnt[s[i]];
    }
    for(int i = 1; i <= n; ++i) {
        col = s[i]; int top = sta[col].size() - 1;
        while(top > 0 && slope(sta[col][top - 1], sta[col][top]) < slope(sta[col][top], i)) sta[col].pop_back(), --top;
        sta[col].push_back(i); ++top;
        while(top > 0 && slope(sta[col][top - 1], sta[col][top]) < 2 * pre[i]) sta[col].pop_back(), --top;
        dp[i] = dp[sta[col][top] - 1] + col * (pre[i] - pre[sta[col][top]] + 1) * (pre[i] - pre[sta[col][top]] + 1);
    }
    printf("%lld\n", dp[n]);
    return 0;
}