#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[20], dp[20][20][3];
LL DFS(int pos, int pre, int state, bool zero, bool limit) {
    if (pos == -1)
        return 1;
    if (!limit && dp[pos][pre][state] != -1) return dp[pos][pre][state];
    int up = limit ? a[pos] : 9;
    LL ans = 0;
    for(int i = 0; i <= up; i++) {
        if(zero) {
            ans += DFS(pos - 1, i, state, zero && i == 0, limit && i == a[pos]);
        }else {
            int st = state;
            if(i < pre) {
                if(st == 0) continue;
                st = 1;
            }
            if(i > pre) {
                if(st == 1) continue;
                st = 0;
            }
            ans += DFS(pos - 1, i, st, false, limit && i == a[pos]);
        }
    }
    if (!limit)
        dp[pos][pre][state] = ans;
    return ans;
}
LL Solve(LL num) {
    int k = 0;
    while (num) {
        a[k++] = num % 10;
        num /= 10;
    }
    return DFS(k - 1, 0, 2, true, true);
}
LL m, l, r;
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> m;
    while (m--) {
        cin >> l >> r;
        cout << Solve(r) - Solve(l - 1)<< endl;
    }
    return 0;
}