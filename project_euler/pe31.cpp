#include <bits/stdc++.h>
using namespace std;
int coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int dp[210];
int main() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = coins[i]; j <= 200; j++) {
            if (j >= coins[i]) dp[j] += dp[j - coins[i]];
        }
    }
    cout << dp[200] << endl;
    return 0;
}