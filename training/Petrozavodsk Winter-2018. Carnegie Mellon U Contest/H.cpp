#include <bits/stdc++.h>
using namespace std;
const int N = 24, NN = 1 << 24, inf = 0x3f3f3f3f;
int w[N];
pair<int, int> dp[NN];
int main() {
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = make_pair(inf, 0);
    }   
    dp[0] = make_pair(0, s);
    for (int S = 0; S < (1 << n); ++S) {
        for (int j = 0; j < n; ++j) {
            if (S & (1 << j)) {
                int last = S ^ (1 << j);
                pair<int, int> np;
                if(dp[last].second + w[j] <= s) {
                    np = make_pair(dp[last].first, dp[last].second + w[j]);
                } else {
                    np = make_pair(dp[last].first + 1, w[j]);
                }
                if(np < dp[S]) dp[S] = np;
            }              
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}