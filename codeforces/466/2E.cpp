#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, c, a[100005], st[100005][35];
LL dp[100005], sum;
int min_(int l, int r) {
    int x = (int)(log(double(r - l + 1)) / log(2.0));
    return min(st[l][x], st[r - (1 << x) + 1][x]);
}
int main() {
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); st[i][0] = a[i]; sum += a[i];
    }
    for(int j = 1; (1 << j) <= n; ++j) {
        for(int i = 1; i + (1 << j - 1) <= n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
    for(int i = c; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - c] + min_(i - c + 1, i));
    }
    cout << sum - dp[n] << endl;
    return 0;
}