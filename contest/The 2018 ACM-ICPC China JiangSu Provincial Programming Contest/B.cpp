#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7, N = 5005;
int n, k;
ll sum[N<<2], dp[N][N];
int main() {
    dp[1][1] = 0; dp[1][0] = 1;
    for(int i = 2; i <= 5000; ++i) {
        sum[0] = dp[i-1][0];
        dp[i][0] = 1;
        for(int j = 1; j <= 5000; ++j) sum[j] = sum[j-1] + dp[i-1][j];
        if(i <= 5) {for(int j = 0; j <= 10; ++j) {
            cout << dp[i-1][j] << " ";
        } cout << endl;}
        for(int j = 1; j <= 5000; ++j) {
            if(min(j,i-1)<=0) dp[i][j] += sum[j];
            else dp[i][j] += sum[j] - sum[j-min(j,i-1)-1];
        }
    }
    for(int i = 1; i <= 5; ++i) {
        for(int j = 0; j <= 5; ++j) {
            cout << i << ":" << j << " " << dp[i][j] << endl;
        }
    }
    //cout << dp[4][3] << endl;
}