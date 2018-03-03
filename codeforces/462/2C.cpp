#include <bits/stdc++.h>
using namespace std;
int n, a[2005], dp[2005][2005], cnt1[2005], cnt2[2005], ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int l1 = 0, l2 = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 1) {
            l1++;
        }else {
            l2 = max(l1, l2) + 1;
        }
    }
    ans = max(l1, l2);
    for(int i = 1; i <= n; ++i) {
        if(a[i] == 1) {
            cnt1[i] = cnt1[i - 1] + 1;
            cnt2[i] = cnt2[i - 1];
        }else {
            cnt1[i] = cnt1[i - 1];
            cnt2[i] = cnt2[i - 1] + 1;
        }
    }
    for(int i = n; i >= 1; --i) {
        for(int j = i - 1; j >= 1; --j) {
            if(a[j] == 1) {
                dp[j][i] = dp[j + 1][i];
            }else {
                dp[j][i] = max(cnt1[i] - cnt1[j], dp[j + 1][i]) + 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            ans = max(ans, cnt1[i - 1] + cnt2[n] - cnt2[j] + dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}