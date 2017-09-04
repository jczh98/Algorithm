#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N = 31;
LL dp[N][N][2][50];
int num[N], temp[N];

LL dfs(int start, int cur, bool state, bool fp, int k)//start表示回文串的起点,cur表示正在搜索的位,state表示目前构成的串是否为回文串
{
    if (cur < 0)
        return state;
    if (!fp && dp[start][cur][state][k + 1] != -1)
        return dp[start][cur][state][k + 1];
    int fpmax = fp ? num[cur] : k;
    LL ret = 0;
    for (int i = 0; i <= fpmax; i++) {
        temp[cur] = i;//枚举该位的值
        if (start == cur && i == 0)//前置0的情况
            ret += dfs(start - 1, cur - 1, state, fp && i == fpmax, k);
        else if (state && cur < (start + 1) / 2)//已经构成回文串
            ret += dfs(start, cur - 1, temp[start - cur] == i, fp && i == fpmax, k);
        else//尚未构成回文串
            ret += dfs(start, cur - 1, state, fp && i == fpmax, k);
    }
    if (!fp)
        dp[start][cur][state][k + 1] = ret;
    return ret;
}

LL f(LL n, int k) {
    int len = 0;
    while (n) {
        num[len++] = n % k;
        n /= k;
    }
    num[len] = 0;
    return dfs(len - 1, len - 1, 1, 1, k - 1);
}

int main() {
    int T;
    scanf("%d", &T);
    long long L, R, l, r, ans, tot;
    memset(dp, -1, sizeof(dp));
    for(int kase = 1; kase <= T; kase++) {
        ans = 0;
        scanf("%lld%lld%lld%lld", &L, &R, &l, &r);
        for(int i = l; i <= r; i++) {
            tot = (f(R, i) - f(L - 1, i));
            ans += tot * i + (R - L + 1 - tot);
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
